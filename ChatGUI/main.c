#include <stdio.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk/gtkx.h>

#include "c_chat.h"

int main(int argc, char *argv[])
{
    GtkWidget *c_chat_window;
    GtkBuilder *builder;

    /* Initialize gtk+*/
    gtk_init (&argc, &argv);

    builder = gtk_builder_new_from_file (C_CHAT_UI_FILE);

    c_chat_window = GTK_WIDGET (gtk_builder_get_object (builder, "C-Chat"));
    gtk_builder_connect_signals (builder, NULL);
    g_signal_connect(c_chat_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show (c_chat_window);

    gtk_main ();
    return 0;

}
