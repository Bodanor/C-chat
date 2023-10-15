#include "chat.h"

static Server *server; /* Static variable that will hold all the data for the server including a linked list of clients */

struct client_t {
    char *username; /* Username once a client is logged in */
    bool is_connected; /* Flag if the user is connected */
    pthread_t thread_client; /* PID of the connected client function */
    int client_socket; /* Client socket */
    struct client_t *next_client; /* Next client in the linked list */
};

struct server_t {
    Client *connected_clients; /* Linked list of all the clients */
    int server_socket; /* Do I really have to explain this one ? */
    pthread_mutex_t linked_client_list_lock; /* Mutex used to access the linked list */
};

/*
** Return the server socket : If successfull
** Return -1 : If a malloc error occured
*/
int create_server(void)
{
    server = (Server*)malloc(sizeof(Server));
    if (server == NULL)
        return -1;

    /* Mutex initialization for the linked list of the clients */
    if (pthread_mutex_init(&server->linked_client_list_lock, NULL) != 0)
        return -1;

    server->connected_clients = NULL;

    server->server_socket = Create_server(DEFAULT_PORT);

    return server->server_socket;
}

/*
** Return 0 : If successfull
** Return -1 : If a malloc error occured
*/
int add_client(int client_socket, pthread_t client_thread)
{
    Client *tmp;
    Client *new_client;

    /* Create the new client pointer */
    new_client = (Client*)malloc(sizeof(Client));
    if (new_client == NULL) {
        pthread_mutex_unlock(&server->linked_client_list_lock); /* Release the mutex if an error occured */
        return 1;
    }

    new_client->next_client = NULL;
    new_client->client_socket = client_socket;
    new_client->is_connected = false;
    new_client->username = NULL;
    new_client->thread_client = client_thread;

    pthread_mutex_lock(&server->linked_client_list_lock); /* Lock the mutex */

    /* If the linked list is empty, we simply assign the new client to the connected_clients pointer */
    if (server->connected_clients == NULL) {
        server->connected_clients = new_client;
    }
    /* If not, we have to get to the last element of the linked list and assign the newly created pointer */
    else {

        tmp = server->connected_clients;
        while (tmp->next_client != NULL)
            tmp = tmp->next_client;

        /* We are at the end of the linked list, interst the new created user there. */
        tmp->next_client = new_client;
    }



    pthread_mutex_unlock(&server->linked_client_list_lock); /* Release the mutex */
    return 0;
}

/* 0 : succes
 *-1 : fail */
int delete_client(int client_socket)
{
    Client * current;
    Client *previous;

    current = server->connected_clients;
    previous = current;

    /* If first element, free the element and assign the head to be NULL */
    if (current != NULL && client_socket == current->client_socket) {
        if (current->username != NULL)
            free(current->username);
        server->connected_clients = current->next_client;
    }
    else {
        while (current != NULL && client_socket != current->client_socket) {
            previous = current;
            current = current->next_client;
        }
        if (current == NULL)
            return -1;
        previous->next_client = current->next_client;
        if (current->username != NULL)
            free(current->username);
        free(current);

    }
    return 0;
}



void broadcast_message(int client_src_socket, Message *client_message)
{
    Client* tmp_ptr;
    int send_error;

    pthread_mutex_lock(&server->linked_client_list_lock); /* Lock the mutex */

    tmp_ptr = server->connected_clients;

    while (tmp_ptr != NULL) {
        if (tmp_ptr->client_socket != client_src_socket) { /* Avoid sending the message back to the original socket */
            if ((send_error = Send_msg(tmp_ptr->client_socket, client_message->data, client_message->data_size)) < 0) {
            }
        }
        tmp_ptr = tmp_ptr->next_client;
    }

    pthread_mutex_unlock(&server->linked_client_list_lock); /* Release the mutex */
}
