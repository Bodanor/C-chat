#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>

#include "chat.h"
#include "sockets.h"


#define CLIENT_INTERNAL_ERROR_MSG "An internal server error occured!"

pthread_mutex_t mutex_client_creation;
pthread_cond_t cond_is_thread_created;
int is_created = 0;

void *_client_thread_func(void *socket)
{
    Message *client_message;
    int receive_error;
    int client_socket;

    /* Protect the variable with a mutex as we are passing th client_socket by reference and it should not change until we copy it to a local variable */
    printf("[SERVER]Lock du mutex dans thread\n");
    pthread_mutex_lock(&mutex_client_creation);

    client_socket = *(int*)socket;
    printf("unlock du mutex dans thread\n");
    is_created = 1;
    pthread_mutex_unlock(&mutex_client_creation);
    printf("Envoi du signal vers main\n");
    pthread_cond_signal(&cond_is_thread_created);

    client_message = NULL;

    if ((add_client(client_socket, pthread_self())) == -1) {
        printf("[SERVER] Failed to add the client !\n");
        Send_msg(client_socket, (uint8_t*)CLIENT_INTERNAL_ERROR_MSG, strlen(CLIENT_INTERNAL_ERROR_MSG));
        close(client_socket);
        pthread_exit(0);
    }

    while (1) {
        if ((receive_error = Receive_msg(client_socket, &client_message)) < 0) {
            close(client_socket);
            delete_client(client_socket);
            pthread_exit(0);
        }
        else {
            broadcast_message(client_socket, client_message);
            destroyMessage(client_message);
            client_message = NULL;
        }
    }

    close(client_socket);
}
int main(int argc, char **argv)
{
    int client_socket;
    int server_socket;
    pthread_t client_thread;

    signal(SIGPIPE, SIG_IGN); /* Ignore the SIGPIPE signal as we handle it by deleting the pid of the user */

    pthread_mutex_init(&mutex_client_creation, NULL); /* Initialization of the mutex to be used between the main and the client thread  */
    pthread_cond_init(&cond_is_thread_created, NULL); /* Initialization of the cond variable */
    if ((server_socket = create_server()) == -1) {
        printf("[SERVER] Initialization failed !\n");
        return 1;
    }

    while(1) {
        is_created = 0;
        client_socket = Accept_connexion(server_socket);
        if (pthread_create(&client_thread, NULL, (void*(*)(void*))_client_thread_func, &client_socket) != 0) {
            printf("[SERVER] Thread creation error...\n");
        }
        else {
            pthread_detach(client_thread);
            printf("[SERVER] Locking mutex in main thread\n");
            pthread_mutex_lock(&mutex_client_creation);
            while (is_created == 0) {
                printf("[SERVER] Waiting for a signal on cond_wait\n");
                pthread_cond_wait(&cond_is_thread_created, &mutex_client_creation);
            }
            printf("[SERVER] Received Cond wait signal\n");
            pthread_mutex_unlock(&mutex_client_creation);
            printf("[SERVER] Unlocking the mutex in main thread\n");
        }
    }

}
