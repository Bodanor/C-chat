#include "c_chat_ui.h"


GtkWidget *InputMessage;
GtkWidget *SendButton;
GtkWidget *HistoryChat;
GtkWidget *StatusLabel;
GtkWidget *PingLabel;
GtkWidget *DropDownMenuItem;
GtkWidget *NewConnectionMenuBar;
GtkWidget *DisconnectMenuBar;
GtkWidget *QuitmenuBar;
GtkWidget *c_chat_window;
GtkBuilder *c_chat_builder;


void init_c_chat_window(void)
{
    /* Load the main c_chat_GUI from the UI file */
    c_chat_builder = gtk_builder_new_from_file (C_CHAT_UI_FILE);
    c_chat_window = GTK_WIDGET (gtk_builder_get_object (c_chat_builder, "C-Chat"));
    gtk_builder_connect_signals (c_chat_builder, NULL);
    g_signal_connect(c_chat_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
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

}
void disconnect_on_clicked(GtkMenuItem *b, gpointer user_data)
{

}
void quit_on_clicked(GtkMenuItem *b, gpointer user_data)
{

}
