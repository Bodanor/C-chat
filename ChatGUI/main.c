#include <stdio.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk/gtkx.h>

#include "chat.h"

#define CHAT_UI_FILE "ChatUi.glade"

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkBuilder *builder;

    /* Initialize gtk+*/
    gtk_init (&argc, &argv);

    builder = gtk_builder_new_from_file (CHAT_UI_FILE);

    window = GTK_WIDGET (gtk_builder_get_object (builder, "C-Chat"));
    gtk_builder_connect_signals (builder, NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show (window);

    gtk_main ();
    return 0;

}