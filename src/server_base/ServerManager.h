#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include<map>
#include<string>

#include "BaseServer.h"
#include "LinearObjectPool.h"
#include "EventPackage.h"
#include "Response.h"
#include "HttpStatus.h"

const int MAX_RESPONSE_BUFFER_COUNT = 500;

typedef LinearObjectPool<ResponseBuffer,MAX_RESPONSE_BUFFER_COUNT>
    ResponseBufferPool;

class ServerManager {
public:
    void initManager();

    void endManager();

    void addServer(BaseServer *server);

    friend int doPost(EventPackage* event,HttpStatus* status);
    friend int endPost(EventPackage* event);
    
private:
    ::std::map<::std::string,BaseServer*> m_map;
    ResponseBufferPool bufferPool;
};

void ServerInit(ServerManager* manager);

#endif

