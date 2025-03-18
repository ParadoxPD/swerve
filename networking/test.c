#include "server.h"
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void launch(struct Server *server) {
    char buffer[1024];
    printf(".............Waiting for Connection................");
    int address_len = sizeof(server->address);
    int new_socket = accept(server->socket, (struct sockaddr *)&server->address,
                            (socklen_t *)&address_len);
    read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    char *hello = "asdasd";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

int main() {
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0,
                                              INADDR_ANY, 8080, 10, &launch);
}
