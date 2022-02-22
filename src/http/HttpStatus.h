#ifndef _HTTP_STATUS_H_
#define _HTTP_STATUS_H_

enum HTTP_TYPE{
    GET = 1,
    HEAD = 2,
    POST = 3,
    PUT = 4,
    DELETE = 5,
    TRACE = 6,
    OPTIONS = 7,
    CONNECT = 8,
    PATCH = 9,
    HTTP_1_0 = 10,
    HTTP_1_1 = 11,
    HTTP_2_0 = 12,
};

const int HTTP_TYPE_COUNT = 12;
extern char http_type_str[20][20];

struct HttpStatus{
    int method;
    char *url;
    int url_len;
    int version;
};


#endif
