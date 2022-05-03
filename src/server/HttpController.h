#ifndef _HTTPCONTROLLER_H_
#define _HTTPCONTROLLER_H_

#include <string>
#include <vector>

#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpController{
public:
    HttpController(::std::initializer_list<::std::string> il);
    virtual ~HttpController();

    virtual int doGet(HttpRequest &req,HttpResponse &resp);
    virtual int doPost(HttpRequest &req,HttpResponse &resp);

    friend class ControllerManager;
private:
    ::std::vector<::std::string> m_url;
};




#endif
