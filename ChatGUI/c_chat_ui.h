#ifndef __C_CHAT__
#define __C_CHAT__

#include <stdio.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk/gtkx.h>
#include <gdk/gdk.h>

#include "server_connect_form.h"

#define C_CHAT_UI_FILE "C-ChatUI.glade"

extern GtkWidget *c_chat_window;

void init_c_chat_window(void);
void send_on_button_clicked(GtkButton *b, gpointer user_data);
void new_connection_on_clicked(GtkMenuItem *b, gpointer user_data);
void disconnect_on_clicked(GtkMenuItem *b, gpointer user_data);
void quit_on_clicked(GtkMenuItem *b, gpointer user_data);
void show_c_chat_ui(void);
void c_chat_starter(void);
void c_chat_stopper(void);
#endif
