#include "HttpController.h"

int HttpController::doGet(HttpRequest &req,HttpResponse &resp){
    return 0;
}
int HttpController::doPost(HttpRequest &req,HttpResponse &resp){
    return 0;
}

HttpController::HttpController(::std::initializer_list<::std::string> il)
:m_url(il) { }

HttpController::~HttpController(){ }