#include "tcp_socket.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


int create_tcp_socket(int *port) {
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket < 0) {
        fprintf(stderr, "Socket creation failed\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(0);

    if (bind(tcp_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Socket binding failed\n");
        close(tcp_socket);
        exit(EXIT_FAILURE);
    }

    socklen_t len = sizeof(server_addr);
    if (getsockname(tcp_socket, (struct sockaddr*)&server_addr, &len) < 0) {
        fprintf(stderr, "Socket name retrieval failed\n");
        close(tcp_socket);
        exit(EXIT_FAILURE);
    }

    *port = ntohs(server_addr.sin_port);
    return tcp_socket;
}

void start_listening(int socket_fd) {
    if (listen(socket_fd, 5) < 0) {
        fprintf(stderr, "Listening failed\n");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening...\n");
}

int accept_connection(int socket_fd) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_socket = accept(socket_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_socket < 0) {
        fprintf(stderr, "Accepting connection failed\n");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
    printf("Connection accepted from %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    return client_socket;
}
