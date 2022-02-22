#include "LoginServer.h"

#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

bool LoginServer::doPost(Request &req,Response &resp){
    string name = req.findParameter("username");
    string pwd = req.findParameter("passward");
    printf("%s\n",req.m_cookie.c_str());

    MysqlRAII sql;
    char buffer[555];
    sprintf(buffer,"SELECT username,passward FROM user where username='%s'",name.c_str());
    if (mysql_query(sql.sql, buffer)) {
        printf("sql error\n");
        return true;
    }
    MYSQL_RES *result = mysql_store_result(sql.sql);
    int num_fields = mysql_num_fields(result);
    MYSQL_FIELD *fields = mysql_fetch_fields(result);
    if (MYSQL_ROW row = mysql_fetch_row(result)) {
        if(strcmp(row[1],pwd.c_str()) == 0){
            //printf("ok\n");
            resp.setBody(::std::string("{\"aaa\":\"ok\"}"));
            resp.setHead(set_cookie_str,"name="+name);
        }
        else
            resp.setBody(::std::string("{\"aaa\":\"error\"}"));
    }
    else printf("error\n");  
   
    mysql_free_result(result);    

    return 0;
}

LoginServer::LoginServer():BaseServer("/Login"){}
LoginServer::~LoginServer(){}

/*
printf("%s %s\n",
        name.c_str(),
        pwd.c_str());
*/
