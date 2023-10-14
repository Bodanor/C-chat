#ifndef __C_CHAT__
#define __C_CHAT__

#include <stdio.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk/gtkx.h>

#include "server_connect_form.h"
#define C_CHAT_UI_FILE "C-ChatUI.glade"

extern GtkWidget *InputMessage;
extern GtkWidget *SendButton;
extern GtkWidget *HistoryChat;
extern GtkWidget *StatusLabel;
extern GtkWidget *PingLabel;
extern GtkWidget *DropDownMenuItem;
extern GtkWidget *NewConnectionMenuBar;
extern GtkWidget *DisconnectMenuBar;
extern GtkWidget *QuitmenuBar;
extern GtkWidget *c_chat_window;
extern GtkBuilder *c_chat_builder;

void init_c_chat_window(void);
void send_on_button_clicked(GtkButton *b, gpointer user_data);
void new_connection_on_clicked(GtkMenuItem *b, gpointer user_data);
void disconnect_on_clicked(GtkMenuItem *b, gpointer user_data);
void quit_on_clicked(GtkMenuItem *b, gpointer user_data);
#endif
