#include "TestCtrl.h"

int TestCtrl::doPost(HttpRequest &req,HttpResponse &resp){
    resp.setHead(content_type_str,application_json_str);
    resp.setBody("{\"sta\":\"OK\"}");

    return 1;
}



