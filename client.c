/**
 * @file client.c
 * @author Muhammad Adiel Firqin Bin Muhamad Subta
 * @brief Implementation of the web client module.
 */

 #include <czmq.h> // for zmq functions
 #include <stdio.h> // for printf

int main(int argc, char **argv) {
    zsock_t *requester = zsock_new(ZMQ_REQ); 
    // connect to the server using a TCP socket
    int connection_result = zsock_connect(requester, "tcp://localhost:5555");
    zstr_send(requester, "Hello from client!"); // send a message to the server
    sleep(1); // wait for 1 second
    char *message = zstr_recv(requester); // receive a reply from the server
    printf("Client received: %s\n", message); // print the received message

    free(message); // free the received message
    zsock_destroy(&requester); // destroy the requester socket
}