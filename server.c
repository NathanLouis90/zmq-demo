/**
 * @file server.c
 * @author Muhammad Adiel Firqin Bin Muhamad Subta
 * @brief Implementation of the web server module.
 */

#include <czmq.h> // for zmq functions
#include <string.h> // for strcmp
#include <stdio.h> // for printf
#include <stdlib.h> // for free

int main(int argc, int **argv) {
    zsock_t *responder = zsock_new(ZMQ_REP); // create a new ZeroMQ socket of type REP (reply)
    int port_number_result = zsock_bind(responder, "tcp://*:5555");  // bind the socket to a TCP port
    if (port_number_result == 5555) {
        printf("Successfully bound to port %d\n", port_number_result);
        while (1)  {
            char *message = zstr_recv(responder); // receive a message from the client
            if (!strcmp(message, "Hello from client!")) {
                printf("Server received: %s\n", message);
                zstr_send(responder, "Hello from server!"); // send a reply to the client
            }

            free(message); // free the received message
        }
   } else {
        printf("Failed to bind to port 5555, got: %d\n", port_number_result);
    }
    
    zsock_destroy(&responder); // destroy the responder socket
    return 0; // return success 
}