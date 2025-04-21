#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>

/**
 * Create a TCP socket and bind it to a specified port.
 *
 * @param port Pointer to the port number to bind the socket to.
 * @return File descriptor of the created socket.
 */
int create_tcp_socket(int *port);

/**
 * Start listening on a TCP socket.
 *
 * @param socket_fd File descriptor of the socket to start listening on.
 */
void start_listening(int socket_fd);

/**
 * Accept a connection on a TCP socket.
 *
 * @param socket_fd File descriptor of the socket to accept a connection on.
 * @return File descriptor of the accepted connection.
 */
int accept_connection(int socket_fd);

#endif
