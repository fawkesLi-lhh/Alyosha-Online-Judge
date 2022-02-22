#include "ServerManager.h"

#include "HttpHandler.h"
#include "Request.h"

ServerManager *manager;

int doPost(EventPackage* event,HttpStatus* status){
    Request req(event->m_buffer,event->m_res);
    Response resp;

    ::std::string url(status->url,status->url_len);
    auto itr = manager->m_map.find(url);
    if(itr == manager->m_map.end()){
        resp.setBody(::std::string("server not find\n"));
    }
    else {
        itr->second->doPost(req,resp);
    }
    ResponseBuffer *buffer = manager->bufferPool.getObject();
    if(buffer == nullptr){
        printf("ResponseBuffer error\n");
        event->m_eventType = EVENT_TYPE_END;
        return 1;
    }
    resp.generateResponse(buffer);
    event->ioves[0].iov_base = &(buffer->head);
    event->ioves[0].iov_len = buffer->head_len;
    event->ioves[1].iov_base = &(buffer->body);
    event->ioves[1].iov_len = buffer->body_len;
    event->user_data = buffer;

    // buffer->head[buffer->head_len] = '\0';
    // buffer->body[buffer->body_len]='\0';
    // printf("%s %s\n",buffer->head,buffer->body);

    return 0;
}

int endPost(EventPackage* event){
    if(event->user_data!=0){
        manager->bufferPool.freeObject((ResponseBuffer* )event->user_data);
    }
    return 0;
}

void filterHttpStatus(HttpStatus* status){ }

void beginServer(){ 
    manager = new ServerManager();
    manager->initManager();
    ServerInit(manager);
}

void endServer(){
    manager->endManager();
    delete manager;
}

void ServerManager::addServer(BaseServer *server){
    m_map[server->m_url] = server;
}

void ServerManager::initManager(){
    bufferPool.initPool();
}

void ServerManager::endManager(){
    bufferPool.endPool();
}
