#ifndef _STATUS_SERVER_H_
#define _STATUS_SERVER_H_

#include "BaseServer.h"

class StatusServer : public BaseServer{
public:
    StatusServer();
    ~StatusServer();

    virtual bool doPost(Request &req,Response &resp);
private:
};


#endif
