#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>

/**
 * Create a UDP socket for broadcasting.
 *
 * @param BROADCAST_PORT The port to bind the socket to.
 * @param broadcast_addr The address to bind the socket to.
 * @return The socket file descriptor.
 */
int create_broadcast_socket(
    const int broadcast_port,
    struct sockaddr_in *broadcast_addr,
    struct sockaddr_in *recv_addr);

/**
 * Send a broadcast message.
 *
 * @param broadcast_socket The socket file descriptor.
 * @param broadcast_addr The address to send the message to.
 * @param message The message to send.
 * @param message_len The length of the message.
 * @return: 0 on success, -1 on failure.
 */
int send_broadcast_message(
    const int broadcast_socket,
    const struct sockaddr_in *broadcast_addr,
    const char *message,
    const size_t message_len);

/**
 * Receive broadcast messages.
 *
 * @param broadcast_socket The socket file descriptor.
 * @param buffer The buffer to store the received message.
 * @param buffer_len The length of the buffer.
 * @param recv_addr The address of the sender.
 * @return: 0 on success, -1 on failure.
 */
int receive_broadcast_messages(
    const int broadcast_socket,
    char *buffer,
    const size_t buffer_len,
    struct sockaddr_in *recv_addr);

#endif
