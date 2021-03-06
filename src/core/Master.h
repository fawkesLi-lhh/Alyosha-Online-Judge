#ifndef _MASTER_H_
#define _MASTER_H_

#include <liburing.h>

#include "Worker.h"

const int WORKER_PORCESS_COUNT = 6;

class Master{
public:
    void beginMaster(int port);

    void endMaster();

private:
    void loopMaster();

    int rebootWorker(pid_t pid);

private:
    int server_sock;
    Uringer uring;
    EventPackage event_for_accept;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    ProcessHandle childHandle[WORKER_PORCESS_COUNT];
};

#endif
