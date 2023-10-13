#include <stdio.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk/gtkx.h>

#include "c_chat_ui.h"
#include "server_connect_form.h"

int main(int argc, char *argv[])
{
    /* Initialize gtk+*/
    gtk_init (&argc, &argv);

    init_server_connect_form();
   // init_c_chat_window();

    //gtk_widget_show(c_chat_window);
    //gtk_window_set_transient_for(GTK_WINDOW(server_form_window), GTK_WINDOW(c_chat_window));
    //gtk_widget_show(server_form_window);
    gtk_main ();
    return 0;

}
