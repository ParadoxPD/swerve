#include "../../include/request.h"
#include <string.h>

void parse_request_body(char *req, char *req_body, int start_pos, int end_pos) {

    strncpy(req_body, req + start_pos, end_pos);
    req_body[end_pos - start_pos + 1] = '\0';
}

void parse_request_headers(char *req, char *req_headers, int start_pos) {

    int pos = start_pos;
    while (pos < strlen(req)) {
        if ((req[pos] == '\n' && req[pos + 1] == '\n') ||
            (req[pos] == '\n' && req[pos + 2] == '\n')) {
            break;
        }
        pos++;
    }
    strncpy(req_headers, req + start_pos, pos);
    req_headers[pos - start_pos + 1] = '\0';
}

void parse_request_type(char *req, char *req_type) {

    int pos = 0;
    while (pos < strlen(req)) {
        if (req[pos] == '\n') {
            break;
        }
        pos++;
    }
    strncpy(req_type, req, pos - 1);
    req_type[pos] = '\0';
}

struct Request request_constructor(char *req, long req_size) {

    struct Request request;

    char req_type[req_size];
    parse_request_type(req, req_type);
    printf("Length : %d\n", (int)strlen(req_type));
    char req_headers[req_size];
    parse_request_headers(req, req_headers, strlen(req_type) + 2);
    char req_body[req_size];
    parse_request_body(req, req_body,
                       strlen(req_headers) + strlen(req_type) + 2, req_size);

    printf("REQUEST TYPE:\n%s\n", req_type);
    printf("HEADERS:\n%s\n", req_headers);
    printf("BODY:\n%s\n", req_body);

    return request;
}
