#include"ServerManager.h"

#include "LoginServer.h"
#include "SubmitServer.h"

void ServerInit(ServerManager* manager){
    manager->addServer(new LoginServer());
    manager->addServer(new SubmitServer());
}


