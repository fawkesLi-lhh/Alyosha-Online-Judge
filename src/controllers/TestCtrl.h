#ifndef _TESTCTRL_H_
#define _TESTCTRL_H_

#include "HttpController.h"

class TestCtrl :public HttpController{
public:
    virtual int doPost(HttpRequest &req,HttpResponse &resp);

    TestCtrl():HttpController({"/Login"}){}
    virtual ~TestCtrl(){ }
private:
    /* data */
    /*千万不要有任何成员变量。。。*/
};




#endif
