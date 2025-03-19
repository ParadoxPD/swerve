#ifndef request_h
#define request_h

#include <stdio.h>

enum Methods {
    GET,
    POST,
    PUT,
    HEAD,
    PATCH,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE,
};

struct Request {
    int Method;
    struct URI *Request_URI; // Convert this to a struct to contain params and
                             // query string
    float HTTPVersion;
};

struct URI {
    char *uri;
};

struct Request request_constructor(char *req, long req_size);

#endif
