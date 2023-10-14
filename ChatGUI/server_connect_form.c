#include "server_connect_form.h"

GtkWidget *IPLineEdit;
GtkWidget *PortLineEdit;
GtkWidget *ConnectButton;
GtkWidget *PingButton;
GtkWidget *ConnectionStatusProgressBar;
GtkWidget *ConnectionStatusLabel;
GtkWidget *server_form_window;
GtkBuilder *server_form_builder;

static int server_socket;
static const char *server_ip;
static int server_port_number;
static pthread_t thread_connection;
static pthread_mutex_t connection_mutex;

static void try_server_connect(void);
static int check_form_is_valid(void);
static void server_connect_error(void);
static void move_dummy_progress_bar(void);
static void kill_progress_bar(void *p);

int check_form_is_valid(void)
{
    const char *ip_address;
    const char *port_number;
    PangoAttrList *attr_list;
    PangoAttribute *attr;

    ip_address = NULL;
    port_number = NULL;

    ip_address = gtk_entry_get_text(GTK_ENTRY(IPLineEdit));
    port_number = gtk_entry_get_text(GTK_ENTRY(PortLineEdit));
    attr_list = pango_attr_list_new();
    if (*ip_address == '\0') {
        attr = pango_attr_foreground_new(65535, 0, 0);
        pango_attr_list_insert(attr_list, attr);
        gtk_label_set_attributes(GTK_LABEL(ConnectionStatusLabel), attr_list);
        gtk_label_set_text(GTK_LABEL(ConnectionStatusLabel), "Ip address is empty !");
    }
    else if (*port_number == '\0') {
        attr = pango_attr_foreground_new(65535, 0, 0);
        pango_attr_list_insert(attr_list, attr);
        gtk_label_set_attributes(GTK_LABEL(ConnectionStatusLabel), attr_list);
        gtk_label_set_text(GTK_LABEL(ConnectionStatusLabel), "Port number is empty !");
    }
    else if (check_is_number(port_number) == 1) {
        attr = pango_attr_foreground_new(65535, 0, 0);
        pango_attr_list_insert(attr_list, attr);
        gtk_label_set_attributes(GTK_LABEL(ConnectionStatusLabel), attr_list);
        gtk_label_set_text(GTK_LABEL(ConnectionStatusLabel), "Port number is invalid !");
    }
    else {
        server_ip = ip_address;
        server_port_number = atoi(port_number);
        return 0;
    }
    return 1;

}
void server_connect_error(void)
{
    PangoAttrList *attr_list;
    PangoAttribute *attr;

    attr_list = pango_attr_list_new();

    attr = pango_attr_foreground_new(65535, 0, 0);
    pango_attr_list_insert(attr_list, attr);
    gtk_label_set_attributes(GTK_LABEL(ConnectionStatusLabel), attr_list);
    gtk_label_set_text(GTK_LABEL(ConnectionStatusLabel), "Connection to the server failed !");

}

void server_ping_sucess(void)
{

    PangoAttrList *attr_list;
    PangoAttribute *attr;

    attr_list = pango_attr_list_new();

    attr = pango_attr_foreground_new(0, 65535, 0);
    pango_attr_list_insert(attr_list, attr);
    gtk_label_set_attributes(GTK_LABEL(ConnectionStatusLabel), attr_list);
    gtk_label_set_text(GTK_LABEL(ConnectionStatusLabel), "Server is UP !");
}
void move_dummy_progress_bar(void)
{

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    pthread_testcancel();

    while (1){
        usleep(100000);
        gtk_progress_bar_pulse(GTK_PROGRESS_BAR(ConnectionStatusProgressBar));
    }
    pthread_exit(0);

}
void kill_progress_bar(void *p)
{
    pthread_t thread_progress_bar;
    thread_progress_bar = *((pthread_t*)p);

    pthread_cancel(thread_progress_bar);
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(ConnectionStatusProgressBar), 0.0);
    pthread_mutex_unlock(&connection_mutex);
}

void try_server_connect(void)
{
    PangoAttrList *attr_list;
    PangoAttribute *attr;
    pthread_t thread_status_bar;

    pthread_mutex_lock(&connection_mutex);

    pthread_cleanup_push(kill_progress_bar, &thread_status_bar);

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    pthread_testcancel();

    pthread_create(&thread_status_bar, NULL, (void*(*)(void*))move_dummy_progress_bar, NULL);
    pthread_detach(thread_status_bar);

    attr_list = pango_attr_list_new();
    attr = pango_attr_foreground_new(65535, 40863, 18247);
    pango_attr_list_insert(attr_list, attr);
    gtk_label_set_attributes(GTK_LABEL(ConnectionStatusLabel), attr_list);
    gtk_label_set_text(GTK_LABEL(ConnectionStatusLabel), "Trying to connect to server ...");

    server_socket = Server_connect(server_ip, server_port_number);
    if (server_socket == -1) {
       server_connect_error();
    }

    pthread_cleanup_pop(1);
    pthread_exit(0);
}

void try_server_ping(void)
{
    PangoAttrList *attr_list;
    PangoAttribute *attr;
    pthread_t thread_status_bar;

    pthread_mutex_lock(&connection_mutex);

    pthread_cleanup_push(kill_progress_bar, &thread_status_bar);

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    pthread_testcancel();

    pthread_create(&thread_status_bar, NULL, (void*(*)(void*))move_dummy_progress_bar, NULL);
    pthread_detach(thread_status_bar);

    attr_list = pango_attr_list_new();
    attr = pango_attr_foreground_new(65535, 40863, 18247);
    pango_attr_list_insert(attr_list, attr);
    gtk_label_set_attributes(GTK_LABEL(ConnectionStatusLabel), attr_list);
    gtk_label_set_text(GTK_LABEL(ConnectionStatusLabel), "Trying to connect to server ...");

    server_socket = Server_connect(server_ip, server_port_number);
    if (server_socket == -1) {
       server_connect_error();
    }
    else {
        server_ping_sucess();
        close(server_socket);
    }
    pthread_cleanup_pop(1);
    pthread_exit(0);

}
void init_server_connect_form(void)
{

    /* Load the server form from the UI file */
    server_form_builder = gtk_builder_new_from_file (SERVER_CONNECT_FORM);
    server_form_window = GTK_WIDGET (gtk_builder_get_object (server_form_builder, "ServerConnectionForm"));
    gtk_builder_connect_signals (server_form_builder, NULL);
    g_signal_connect(server_form_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    IPLineEdit = GTK_WIDGET(gtk_builder_get_object(server_form_builder, "IPLineEdit"));
    PortLineEdit = GTK_WIDGET(gtk_builder_get_object(server_form_builder, "PortLineEdit"));
    ConnectButton = GTK_WIDGET(gtk_builder_get_object(server_form_builder, "ConnectButton"));
    PingButton = GTK_WIDGET(gtk_builder_get_object(server_form_builder, "PingButton"));
    ConnectionStatusProgressBar = GTK_WIDGET(gtk_builder_get_object(server_form_builder, "ConnectionStatusProgressBar"));
    ConnectionStatusLabel = GTK_WIDGET(gtk_builder_get_object(server_form_builder, "ConnectionStatusLabel"));

    pthread_mutex_init(&connection_mutex, NULL);

}

void ConnectButton_clicked_cb(GtkButton *b, gpointer user_data)
{
    static int connection_in_progress = 0;

    if (check_form_is_valid() == 0) {
        if (connection_in_progress){
            pthread_cancel(thread_connection);
            connection_in_progress = 0;
        }
        pthread_mutex_lock(&connection_mutex);
        pthread_create(&thread_connection, NULL, (void*(*)(void*))try_server_connect, NULL);
        pthread_detach(thread_connection);
        connection_in_progress = 1;
        pthread_mutex_unlock(&connection_mutex);
    }

}
void PingButton_clicked_cb(GtkButton *b, gpointer user_data)
{
    static int connection_in_progress = 0;
    if (check_form_is_valid() == 0) {
        if (connection_in_progress){
            pthread_cancel(thread_connection);
            connection_in_progress = 0;
        }
        pthread_mutex_lock(&connection_mutex);
        pthread_create(&thread_connection, NULL, (void*(*)(void*))try_server_ping, NULL);
        pthread_detach(thread_connection);
        connection_in_progress = 1;
        pthread_mutex_unlock(&connection_mutex);
    }

}

void show_connect_form(void)
{
    gtk_widget_show(c_chat_window);
    gtk_widget_show(server_form_window);
    gtk_window_present(GTK_WINDOW(server_form_window));
    gtk_window_set_transient_for(GTK_WINDOW(server_form_window), GTK_WINDOW(c_chat_window));
}
