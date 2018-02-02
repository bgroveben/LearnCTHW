#include <assert.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "window.h"
#include "db.h"
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

// the encapsulation of a client thread, i.e., the thread that handles
// commands from clients
typedef struct Client {
	pthread_t thread;
	window_t *win;
} Client_t;

void *RunClient(void *);
int handle_command(char *, char *, int len);

Client_t *Client_constructor(int ID) {
	Client_t *new_Client = (Client_t *)malloc(sizeof(Client_t));
	char title[16];

	if (new_Client == 0)
		return 0;
	sprintf(title, "Client %d", ID);
	new_Client->win = window_constructor(title);
		// this constructor creates a window and sets up
		// a communication channel with it

	return new_Client;
}

void Client_destructor(Client_t *client) {
	window_destructor(client->win);
		// the destructor removes the window
	free(client);
}

// code executed by the client
void* RunClient(void *arg) {
	Client_t *client = (Client_t *) arg;
		 
	// main loop of the client: fetch commands from window, interpret
	// and handle them, return results to window.
	char command[256];
	char response[256] = {0}; // response must be null for the first call to serve

	serve(client->win, response, command);
	while(handle_command(command, response, sizeof(response))) {
		serve(client->win, response, command);
	}
	return 0;
}

int handle_command(char *command, char *response, int len) {
	if (command[0] == EOF) {
		strncpy(response, "all done", len-1);
		return(0);
	} else {
		interpret_command(command, response, len);
	}
	return(1);
}

int main(int argc, char *argv[]) {
	Client_t *c;

	if (argc != 1) {
		fprintf(stderr, "Usage: server\n");
		exit(1);
	}
	c = Client_constructor(0);
	RunClient((void *)c);
	Client_destructor(c);
	return(0);
}
