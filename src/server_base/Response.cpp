#include "Response.h"

#include <string.h>
#include <stdio.h>

char*OK_200_TITLE = "HTTP/1.1 200 OK\r\n";
char*NOT_FOUND_404_TITLE = "HTTP/1.1 404 Not Found\r\n";
int OK_200_TITLE_LEN = strlen(OK_200_TITLE);
int NOT_FOUND_404_TITLE_LEN = strlen(NOT_FOUND_404_TITLE);

::std::string set_cookie_str = "Set-Cookie";
::std::string content_type_str = "Content-Type";
char *content_length_str = "Content-Length: %d\r\n\r\n";

void Response::generateResponse(ResponseBuffer* buffer){
    buffer->body_len = 0;
    buffer->head_len = 0;
    switch (m_type){
    case OK_200:
        memcpy(buffer->head,OK_200_TITLE,OK_200_TITLE_LEN);
        buffer->head_len+=OK_200_TITLE_LEN;
        break;
    default:
        memcpy(buffer->head,NOT_FOUND_404_TITLE,NOT_FOUND_404_TITLE_LEN);
        buffer->head_len+=NOT_FOUND_404_TITLE_LEN;
        break;
    }
    for(auto &itr:m_map){
        memcpy(buffer->head+buffer->head_len,itr.first.c_str(),itr.first.size());
        buffer->head_len+=itr.first.size();
        memcpy(buffer->head+buffer->head_len,": ",2);
        buffer->head_len+=2;
        memcpy(buffer->head+buffer->head_len,itr.second.c_str(),itr.second.size());
        buffer->head_len+=itr.second.size();
        memcpy(buffer->head+buffer->head_len,"\r\n",2);
        buffer->head_len+=2;
    }
    char content_length_buffer[555];
    memset(content_length_buffer,0,sizeof(char)*555);
    sprintf(content_length_buffer,content_length_str,m_body.size());
    int content_length_buffer_len = strlen(content_length_buffer);
    memcpy(buffer->head+buffer->head_len,content_length_buffer,content_length_buffer_len);
    buffer->head_len+=content_length_buffer_len;
    buffer->head[buffer->head_len] = '\0';

    memcpy(buffer->body,m_body.c_str(),m_body.size());
    buffer->body_len+=m_body.size();
    buffer->body[buffer->body_len] = '\0';
}

Response::Response():m_type(OK_200){
    setHead(content_type_str,::std::string("text/html"));
}
Response::~Response(){ }
