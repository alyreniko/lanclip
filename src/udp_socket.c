#include "udp_socket.h"
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <uv.h>

int create_broadcast_socket(const int broadcast_port, struct sockaddr_in *broadcast_addr, struct sockaddr_in *recv_addr) {
    int udp_socket;

    if ((udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        fprintf(stderr, "Error creating socket\n");
        return -1;
    }

    int broadcast_enable = 1;
    if (setsockopt(udp_socket, SOL_SOCKET, SO_BROADCAST, &broadcast_enable, sizeof(broadcast_enable)) < 0) {
        fprintf(stderr, "Error setting socket option\n");
        close(udp_socket);
        return -1;
    }

    memset(broadcast_addr, 0, sizeof(*broadcast_addr));
    broadcast_addr->sin_family = AF_INET;
    broadcast_addr->sin_port = htons(broadcast_port);
    broadcast_addr->sin_addr.s_addr = htonl(INADDR_BROADCAST);

    memset(recv_addr, 0, sizeof(*recv_addr));
    recv_addr->sin_family = AF_INET;
    recv_addr->sin_port = htons(broadcast_port);
    recv_addr->sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(udp_socket, (struct sockaddr *)recv_addr, sizeof(*recv_addr)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        close(udp_socket);
        return -1;
    }

    return udp_socket;
}

int send_broadcast_message(const int broadcast_socket, const struct sockaddr_in *broadcast_addr, const char *message, const size_t message_len) {
    if (sendto(broadcast_socket, message, message_len, 0, (const struct sockaddr *)broadcast_addr, sizeof(*broadcast_addr)) < 0) {
        fprintf(stderr, "Error sending broadcast message\n");
        return -1;
    }
    return 0;
}

int receive_broadcast_messages(const int broadcast_socket, char *buffer, const size_t buffer_len, struct sockaddr_in *recv_addr) {
    socklen_t addr_len = sizeof(*recv_addr);
    ssize_t recv_len = recvfrom(broadcast_socket, buffer, buffer_len, 0, (struct sockaddr *)recv_addr, &addr_len);
    if (recv_len < 0) {
        fprintf(stderr, "Error receiving broadcast message\n");
        return -1;
    }
    buffer[recv_len] = '\0';
    return 0;
}
