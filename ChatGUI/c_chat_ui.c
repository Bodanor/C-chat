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
static GtkBuilder *c_chat_builder;

static void close_button_clicked(void);

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

}



void send_on_button_clicked(GtkButton *b, gpointer user_data)
{

}
void new_connection_on_clicked(GtkMenuItem *b, gpointer user_data)
{
    show_connect_form();
    close(server_socket);

}
void disconnect_on_clicked(GtkMenuItem *b, gpointer user_data)
{
    new_connection_on_clicked(b, user_data);

}
void quit_on_clicked(GtkMenuItem *b, gpointer user_data)
{
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
    close(server_socket);
    show_c_chat_ui();
    show_connect_form();
}
