#ifndef _HTTP_HANDLER_H_
#define _HTTP_HANDLER_H_

#include "Tire.h"
#include "HttpStatus.h"
#include "FileHandler.h"

#include "EventPackage.h"


class HttpHandler{
public:
    void initHander();

    void endHander();

    void processHttp(EventPackage *event);

private:
    HttpStatus processHttpHead(char* str,int len);

private:
    Tire tire;
    FileHandler fileHandler;
};

void processEvent(EventPackage* event);

void onInitWorker();

void onEndWorker();

void filterHttpStatus(HttpStatus* status);

int doPost(EventPackage* event,HttpStatus* status);

int endPost(EventPackage* event);

void beginServer();

void endServer();

#endif