#include "server.h"
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void launch(struct Server *server) {
    const char *http_response = "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Connection: close\r\n"
                                "\r\n"
                                "<!DOCTYPE html>\r\n"
                                "<html>\r\n"
                                "<head><title>Hello</title></head>\r\n"
                                "<body><h1>Hello World</h1></body>\r\n"
                                "</html>\r\n";
    char buffer[1024];
    int address_len = sizeof(server->address);
    // printf("Hello 3");
    while (1) {
        printf(".............Waiting for Connection................\n");
        int new_socket =
            accept(server->socket, (struct sockaddr *)&server->address,
                   (socklen_t *)&address_len);
        read(new_socket, buffer, 1024);
        printf("%s\n", buffer);

        write(new_socket, http_response, strlen(http_response));
        close(new_socket);
    }
}

int main() {
    //    printf("Hello 0\n");
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0,
                                              INADDR_ANY, 8080, 10, launch);
    // printf("Hello 2\n");
    server.launch(&server);
    return 0;
}
