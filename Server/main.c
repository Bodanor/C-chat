#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "chat.h"
#include "sockets.h"


#define CLIENT_INTERNAL_ERROR_MSG "An internal server error occured!"

void *_client_thread_func(void *socket)
{
    Message *client_message;
    int receive_error;

    client_message = NULL;

    if ((add_client(*(int*)socket, pthread_self())) == -1) {
        printf("[SERVER] Failed to add the client !\n");
        Send_msg(*(int*)socket, (uint8_t*)CLIENT_INTERNAL_ERROR_MSG, strlen(CLIENT_INTERNAL_ERROR_MSG));
        close(*(int*)socket);
        pthread_exit(0);
    }

    while (1) {
        if ((receive_error = Receive_msg(*(int*)socket, &client_message)) < 0) {
            close(*(int*)socket);
            pthread_exit(0);
        }
        else {
            broadcast_message(*(int*)socket, client_message);
            destroyMessage(client_message);
            client_message = NULL;
        }
    }

    close(*(int*)socket);
}
int main(int argc, char **argv)
{
    int client_socket;
    int server_socket;
    pthread_t client_thread;

    signal(SIGPIPE, SIG_IGN); /* Ignore the SIGPIPE signal as we handle it by deleting the pid of the user */

    if ((server_socket = create_server()) == -1) {
        printf("[SERVER] Initialization failed !\n");
        return 1;
    }

    while(1) {
        client_socket = Accept_connexion(server_socket);
        if (pthread_create(&client_thread, NULL, (void*(*)(void*))_client_thread_func, &client_socket) != 0) {
            printf("[SERVER] Thread creation error...\n");
        }
        else {
            pthread_detach(client_thread);
        }
    }

}
