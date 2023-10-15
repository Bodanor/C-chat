#include "c_chat_ui.h"

GtkWidget *c_chat_window;

static GtkWidget *InputMessage;
static GtkWidget *SendButton;
static GtkWidget *HistoryChat;
static GtkWidget *StatusLabel;
static GtkWidget *PingLabel;
static GtkWidget *DropDownMenuItem;
static GtkWidget *NewConnectionMenuBar;
static GtkWidget *DisconnectMenuBar;
static GtkWidget *QuitmenuBar;
static GtkWidget *ScrolledWindow;
static GtkBuilder *c_chat_builder;
static pthread_t thread_recv;
static pthread_mutex_t mutex_history_chat;
static pthread_mutex_t mutex_ping_label;
static pthread_mutex_t mutex_status_label;
static pthread_cond_t cond_add_history;
static int is_added_to_history = 0;

static void close_button_clicked(void);
static void *_recv_function();
static void disconnected_status(void);
static void connected_status(void);
static void clear_ping(void);
static gboolean append_to_history(gpointer data);
static void clear_c_chat_elements(void);

void init_c_chat_window(void)
{
    /* Load the main c_chat_GUI from the UI file */
    c_chat_builder = gtk_builder_new_from_file (C_CHAT_UI_FILE);
    c_chat_window = GTK_WIDGET (gtk_builder_get_object (c_chat_builder, "C-Chat"));
    gtk_builder_connect_signals (c_chat_builder, NULL);
    g_signal_connect(c_chat_window, "delete-event", G_CALLBACK(close_button_clicked), NULL);
    InputMessage = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "InputMessage"));
    SendButton = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "SendButton"));
    HistoryChat = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "HistoryChat"));
    StatusLabel = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "StatusLabel"));
    PingLabel = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "PingLabel"));
    DropDownMenuItem = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "DropDownMenuItem"));
    NewConnectionMenuBar = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "NewConnectionMenuBar"));
    DisconnectMenuBar = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "DisconnectMenuBar"));
    QuitmenuBar = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "QuitmenuBar"));
    ScrolledWindow = GTK_WIDGET(gtk_builder_get_object(c_chat_builder, "ScrolledWindow"));
    pthread_mutex_init(&mutex_history_chat, NULL);
    pthread_mutex_init(&mutex_ping_label, NULL);
    pthread_mutex_init(&mutex_status_label, NULL);
    pthread_cond_init(&cond_add_history, NULL);

}


void send_on_button_clicked(GtkButton *b, gpointer user_data)
{
    int error_status;
    const gchar *message;
    char *sended_string;

    message = gtk_entry_get_text(GTK_ENTRY(InputMessage));

    error_status = Send_msg(server_socket, (const uint8_t*)message, strlen((const char*)message) + 1);
    if (error_status < 0) {
        disconnected_status();
        clear_ping();
    }
    else {
        sended_string = append_username("You", (const char*)message); /* How can I verify that i succeedes. What should I do ? */

        append_to_history(sended_string);
    }

    gtk_entry_set_text(GTK_ENTRY(InputMessage), ""); /* Clear the Input entry */

}
void new_connection_on_clicked(GtkMenuItem *b, gpointer user_data)
{
    c_chat_stopper();
    show_connect_form();
    clear_c_chat_elements();
    close(server_socket);

}
void disconnect_on_clicked(GtkMenuItem *b, gpointer user_data)
{
    new_connection_on_clicked(b, user_data);

}
void quit_on_clicked(GtkMenuItem *b, gpointer user_data)
{
    c_chat_stopper();
    clear_c_chat_elements();
    close(server_socket);
    gtk_main_quit();
}

void show_c_chat_ui(void)
{
    gtk_widget_set_visible(c_chat_window, gtk_true());
    gtk_widget_show(c_chat_window);
    gtk_window_present(GTK_WINDOW(c_chat_window));
}

void close_button_clicked(void)
{
    c_chat_stopper();
    close(server_socket);
    clear_c_chat_elements();
    show_c_chat_ui();
    show_connect_form();
}

void c_chat_starter(void)
{
    pthread_create(&thread_recv, NULL, (void*(*)(void*))_recv_function, NULL);
    pthread_detach(thread_recv);
    connected_status();
}
void c_chat_stopper(void)
{
    pthread_cancel(thread_recv);
}

static void *_recv_function()
{
    Message *msg;
    int error_status;

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    pthread_testcancel();

    while (1) {
        msg = NULL;
        error_status = Receive_msg(server_socket, &msg);
        if (error_status < 0) {
            disconnected_status();
            clear_ping();
            break;
        }
        else {
            is_added_to_history = 0;
            gdk_threads_add_idle(append_to_history, (gpointer)msg->data);
            pthread_mutex_lock(&mutex_history_chat);
            while (is_added_to_history == 0)
                pthread_cond_wait(&cond_add_history, &mutex_history_chat);
            pthread_mutex_unlock(&mutex_history_chat);

            destroyMessage(msg);
        }

    }
    pthread_exit(0);
}

static void disconnected_status(void)
{
    PangoAttrList *attr_list;
    PangoAttribute *attr;

    attr_list = pango_attr_list_new();
    attr = pango_attr_foreground_new(65535, 0, 0);
    pango_attr_list_insert(attr_list, attr);
    gtk_label_set_attributes(GTK_LABEL(StatusLabel), attr_list);

    pthread_mutex_lock(&mutex_status_label);
    gtk_label_set_text(GTK_LABEL(StatusLabel), "Disconnected");
    pthread_mutex_unlock(&mutex_status_label);

}
static void connected_status(void)
{
    PangoAttrList *attr_list;
    PangoAttribute *attr;

    attr_list = pango_attr_list_new();
    attr = pango_attr_foreground_new(0, 65535, 0);
    pango_attr_list_insert(attr_list, attr);
    gtk_label_set_attributes(GTK_LABEL(StatusLabel), attr_list);

    pthread_mutex_lock(&mutex_status_label);
    gtk_label_set_text(GTK_LABEL(StatusLabel), "Connected");
    pthread_mutex_unlock(&mutex_status_label);
}
static void clear_ping(void)
{
    pthread_mutex_lock(&mutex_ping_label);
    gtk_label_set_text(GTK_LABEL(PingLabel), "");
    pthread_mutex_unlock(&mutex_ping_label);
}

static gboolean append_to_history(gpointer data)
{
    const gchar *text;
    GtkTextBuffer *history_buffer;
    GtkTextIter iter;


    pthread_mutex_lock(&mutex_history_chat);

    text = (const gchar*)data;

    history_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(HistoryChat));
    gtk_text_buffer_get_end_iter(history_buffer, &iter);
    gtk_text_buffer_insert(history_buffer, &iter, text, -1);
    gtk_text_buffer_get_end_iter(history_buffer, &iter);
    gtk_text_buffer_insert(history_buffer, &iter, "\n", -1);

    GtkAdjustment *v_adjustment = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(ScrolledWindow));
    gtk_adjustment_set_value(v_adjustment, gtk_adjustment_get_upper(v_adjustment));

    is_added_to_history = 1;
    pthread_mutex_unlock(&mutex_history_chat);
    pthread_cond_signal(&cond_add_history);

}

void clear_c_chat_elements(void)
{
    GtkTextBuffer *buffer;


    pthread_mutex_lock(&mutex_ping_label);
    gtk_label_set_text(GTK_LABEL(PingLabel), "");
    pthread_mutex_unlock(&mutex_ping_label);

    pthread_mutex_lock(&mutex_status_label);
    pthread_mutex_unlock(&mutex_status_label);
    gtk_label_set_text(GTK_LABEL(StatusLabel), "");


    pthread_mutex_lock(&mutex_history_chat);
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(HistoryChat));
    gtk_text_buffer_set_text(buffer, "", -1);
    pthread_mutex_unlock(&mutex_history_chat);

    gtk_entry_set_text(GTK_ENTRY(InputMessage), "");
}
