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
    init_c_chat_window();

    show_connect_form();
    gtk_main();

}
