#ifndef _CONTROLLERMANAGER_H_
#define _CONTROLLERMANAGER_H_

#include <string>
#include <map>

#include "EventPackage.h"
#include "HttpStatus.h"
#include "HttpController.h"

class ControllerManager{
public:
    virtual void addController(HttpController *c);
    friend int doController(HttpStatus status,EventPackage *event);
private:
    ::std::map<::std::string,HttpController*> mp;
};

void initController(ControllerManager* manager);

#endif
