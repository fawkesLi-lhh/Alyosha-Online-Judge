#include<string.h>
#include<stdio.h>

#include "Master.h"

char *ok_respone="HTTP/1.0 200 OK\nContent-Type: text/html\nContent-Length: 5\n\nHello";//
int ok_respone_len = strlen(ok_respone);

void onInitWorker(){

}

void onEndWorker(){
    
}

void processEvent(EventPackage* event){
    switch (event->m_eventType) {
    case EVENT_TYPE_READ:
        event->m_eventType=EVENT_TYPE_WRITE;
        memcpy(event->m_buffer,ok_respone,ok_respone_len);
        event->m_buffer[ok_respone_len]='\0';
        event->len=ok_respone_len;
        break;
    case EVENT_TYPE_WRITE:
        event->m_eventType = EVENT_TYPE_END;
        break;
    default: break;
    }
}

signed main(){
    Master master;
    master.beginMaster(9856);
    
    return 0;
}