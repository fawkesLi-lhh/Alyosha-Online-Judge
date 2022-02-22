#ifndef _LONIN_SERVER_H_
#define _LONIN_SERVER_H_

#include "BaseServer.h"

class LoginServer : public BaseServer{
public:
    LoginServer();
    ~LoginServer();

    virtual bool doPost(Request &req,Response &resp);
private:
};




#endif
