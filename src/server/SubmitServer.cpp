#include "SubmitServer.h"

#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int count = 0;

bool SubmitServer::doPost(Request &req,Response &resp){
    string code = req.findParameter("code");
    char* n_code = urlDecode(code.c_str());
    int code_len = strlen(n_code);
    printf("%s\n",n_code);

    


    resp.setBody(::std::string("{\"aaa\":\"ok\"}"));
    delete[] n_code;
    return 0;
}

SubmitServer::SubmitServer():BaseServer("/Submit"){}
SubmitServer::~SubmitServer(){}
