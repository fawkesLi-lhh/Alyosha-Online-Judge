#ifndef _BASE_SERVER_H_
#define _BASE_SERVER_H_

#include <string>

#include "Request.h"
#include "Response.h"
#include "MysqlRAII.h"
#include "urldecode.h"

class BaseServer{
public:
    virtual bool doPost(Request &req,Response &resp) = 0;
    BaseServer(::std::string url);
    virtual ~BaseServer();

    friend class ServerManager;
private:
    ::std::string m_url;
};


#endif