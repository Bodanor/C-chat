#ifndef __SERVER_CONNECT_FORM__
#define __SERVER_CONNECT_FORM__

#include <gtk-3.0/gtk/gtk.h>
#include <gtk/gtkx.h>

#include "pthread.h"
#include "util.h"
#include "c_chat_ui.h"
#include "sockets.h"

#define SERVER_CONNECT_FORM "ServerConnectForm.glade"


extern GtkWidget *server_form_window;
extern int server_socket;

void init_server_connect_form(void);
void ConnectButton_clicked_cb(GtkButton *b, gpointer user_data);
void PingButton_clicked_cb(GtkButton *b, gpointer user_data);
void show_connect_form(void);
void unshow_connect_form(void);
#endif
