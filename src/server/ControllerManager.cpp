#include "ControllerManager.h"

#include<iostream>

using namespace std;

ControllerManager *controllerManager;
int doController(HttpStatus status,EventPackage *event){
    status.url[status.url_len] = ' ';

    HttpRequest req(event->m_buffer,event->m_res);
    HttpResponse resp;

    //::std::cout<<::std::string(status.url,status.url_len)<<::std::endl;
    //cout<<status.version<<endl;
    auto itr = controllerManager->mp.find(::std::string(status.url,status.url_len));
    if(itr == controllerManager->mp.end())return 0;
    if(status.method == GET){
        itr->second->doGet(req,resp);
    }
    else if(status.method == POST){
        itr->second->doPost(req,resp);
    }
    
    resp.generateResponse(event);
    event->ioves[0].iov_base = &(event->head);
    event->ioves[0].iov_len = event->head_len;
    event->ioves[1].iov_base = &(event->body);
    event->ioves[1].iov_len = event->body_len;
    event->m_eventType = EVENT_TYPE_WRITEV;

    return 1;
}

void initServer(){
    controllerManager = new ControllerManager();
    initController(controllerManager);
}

void ControllerManager::addController(HttpController *c){
    for(auto& str : c->m_url){
        mp[str] = c;
    }
}
