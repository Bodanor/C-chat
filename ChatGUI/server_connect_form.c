#include "server_connect_form.h"

GtkWidget *IPLineEdit;
GtkWidget *PortLineEdit;
GtkWidget *ConnectButton;
GtkWidget *PingButton;
GtkWidget *ConnectionStatusProgressBar;
GtkWidget *ConnectionStatusLabel;
GtkWidget *server_form_window;
GtkBuilder *server_form_builder;

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
}

void ConnectButton_clicked_cb(GtkButton *b, gpointer user_data)
{

}
void PingButton_clicked_cb(GtkButton *b, gpointer user_data)
{

}
