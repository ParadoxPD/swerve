#include "../include/request.h"
#include "../include/server.h"
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

// static volatile int running = 1;
// void sig_handler(int sig) {
//     printf("STOPPED");
//     running = 0;
// }
//
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
    int buffer_size = 1024 * 1024;
    char request_string[buffer_size];
    int address_len = sizeof(server->address);
    struct Request request;
    // printf("Hello 3");
    while (1) {
        printf(".............Waiting for Connection................\n");
        int new_socket =
            accept(server->socket, (struct sockaddr *)&server->address,
                   (socklen_t *)&address_len);
        read(new_socket, request_string, buffer_size);
        printf("%s\n----------------------------\n", request_string);
        request = request_constructor(request_string, strlen(request_string));

        write(new_socket, http_response, strlen(http_response));
        close(new_socket);
    }
}

int main() {
    // signal(SIGINT, sig_handler);
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0,
                                              INADDR_ANY, 8080, 10, launch);
    // printf("Hello 2\n");
    server.launch(&server);
    close(server.socket);
    return 0;
}
