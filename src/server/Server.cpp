#include "Tire.h"
#include "FileHandler.h"
#include "Server.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/uio.h>
#include <sys/mman.h>

char *error_404_head = "HTTP/1.1 404 Not Found\r\nConnection: close\r\nContent-Type: text/html\r\nContent-Length: 16\r\n\r\n";
char *error_404_body = "File f not found\r\n";
//Connection: close\r\n
char *ok_200_head = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n";
//char *ok_200_head = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n";
int error_404_head_len = strlen(error_404_head);
int error_404_body_len = strlen(error_404_body);

char *default_url_recv = "/";
char *default_url_real = "/index.html";

Tire http_type_tire;
FileHandler fileHandler;


void processEvent(EventPackage* event){
    switch (event->m_eventType) {
    case EVENT_TYPE_READ:
        event->user_data = 0;
        processHttp(event);
        break;
    default: event->m_eventType = EVENT_TYPE_END;
    break;
    }
}
void processHttp(EventPackage *event){
    HttpStatus status = processHttpHead(event->m_buffer,event->m_res);
    if(status.method == 0||status.url == 0||status.version == 0){
        event->m_eventType = EVENT_TYPE_END;
        return;
    }
    if(memcmp(status.url,default_url_recv,2)==0){
        //when "/" coming,we replay it as "/index.html"
        status.url = default_url_real;
        status.url_len = strlen(default_url_real);
    }
    
    switch(status.method){
        case GET:
            if(fileAccess(status,event))break;
            if(doController(status,event))break;
            bad_request_404(event);
            break;
        case POST:
            if(doController(status,event))break;
            bad_request_404(event);
            break;
        default:break;
    }
}

int fileAccess(HttpStatus status,EventPackage *event){
    FileNode file;
    file = fileHandler.processUrl(status.url,0);
    if(file.statue == FILE_TYPE_NULL) return 0;
    else if(file.statue == FILE_TYPE_BUFFER_MMAP){
        sprintf(event->m_buffer,ok_200_head,file.content_type,file.len);
        //sprintf(event->m_buffer,ok_200_head,file.len);
        event->ioves[0].iov_base = event->m_buffer;
        event->ioves[0].iov_len=strlen(event->m_buffer);
        event->ioves[1].iov_base = file.data;
        event->ioves[1].iov_len = file.len;
        event->iovec_cnt = 2;
        event->m_eventType = EVENT_TYPE_WRITEV;
    }
    return 1;
}

void bad_request_404(EventPackage *event){
    event->ioves[0].iov_base = error_404_head;
    event->ioves[0].iov_len=error_404_head_len;
    event->ioves[1].iov_base = error_404_body;
    event->ioves[1].iov_len = error_404_body_len;
    event->iovec_cnt = 2;
    event->m_eventType = EVENT_TYPE_WRITEV;
}

HttpStatus processHttpHead(char* str,int len){
    HttpStatus status;
    memset(&status,0,sizeof(status));
    int now = 0,tlen = 20;
    do{
        status.method=http_type_tire.findString(str+now,&tlen);
        if(status.method == 0)break;
        now+=tlen+1;
        status.url = str+now;
        while(str[now]!=' ')now++;
        str[now] = '\0';
        status.url_len=(str+now)-status.url;
        now++;
        tlen = 20;
        status.version = http_type_tire.findString(str+now,&tlen);
    }while(0);
    
    return status;
}

void onInitWorker(){
    int flag = 0;
    http_type_tire.initTire();
    for(int i = 0;i<HTTP_TYPE_COUNT;i++){
        flag = http_type_tire.insertString(http_type_str[i],strlen(http_type_str[i]),i+1);
        if(flag == 0){
            //There's no way to get to this row
            printf("too many Http type\n");
            exit(0);
        }
    }
    fileHandler.initHander();
    initServer();
}

void onEndWorker(){
    http_type_tire.endTire();
    fileHandler.endHander();
}
