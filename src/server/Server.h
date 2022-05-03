#ifndef _SERVER_H_
#define _SERVER_H_

#include "EventPackage.h"
#include "HttpStatus.h"

void processHttp(EventPackage *event);

HttpStatus processHttpHead(char* str,int len);

int fileAccess(HttpStatus status,EventPackage *event);
int doController(HttpStatus status,EventPackage *event);
void bad_request_404(EventPackage *event);

void initServer();

#endif
