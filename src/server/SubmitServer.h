#ifndef _SUBMIT_SERVER_H_
#define _SUBMIT_SERVER_H_

#include "BaseServer.h"

class SubmitServer : public BaseServer{
public:
    SubmitServer();
    ~SubmitServer();

    virtual bool doPost(Request &req,Response &resp);
private:
};


#endif
