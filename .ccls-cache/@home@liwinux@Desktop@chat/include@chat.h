#ifndef __CHAT__
#define __CHAT__

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

#include "sockets.h"

#define DEFAULT_PORT 4444
typedef struct client_t Client;
typedef struct server_t Server;

int create_server(void);
int add_client(int client_socket, pthread_t client_thread);
int delete_client(int client_socket);
void broadcast_message(int client_src_socket, Message *client_message);
#endif
