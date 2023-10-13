#ifndef __SERVER_CONNECT_FORM__
#define __SERVER_CONNECT_FORM__

#include <gtk-3.0/gtk/gtk.h>
#include <gtk/gtkx.h>

#define SERVER_CONNECT_FORM "ServerConnectForm.glade"


extern GtkWidget *IPLineEdit;
extern GtkWidget *PortLineEdit;
extern GtkWidget *ConnectButton;
extern GtkWidget *PingButton;
extern GtkWidget *ConnectionStatusProgressBar;
extern GtkWidget *ConnectionStatusLabel;
extern GtkWidget *server_form_window;
extern GtkBuilder *server_form_builder;

void init_server_connect_form(void);
void ConnectButton_clicked_cb(GtkButton *b, gpointer user_data);
void PingButton_clicked_cb(GtkButton *b, gpointer user_data);


#endif
