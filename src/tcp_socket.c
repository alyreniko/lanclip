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
