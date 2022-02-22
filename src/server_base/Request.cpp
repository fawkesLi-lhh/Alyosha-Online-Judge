#include "Request.h"

#include <string.h>
#include <stdio.h>

char *cookie_str = "Cookie:";
int cookie_str_length = strlen(cookie_str);

::std::string Request::findParameter(::std::string str){
    if(m_form.size() == 0)return ::std::string();
    ::std::string::size_type now =m_form.find(str);
    if (now == std::string::npos) {
        //printf("aaa\n");
        return ::std::string();
    }
    
    while(m_form[now]!='='&&now<m_form.size())now++;
    if(now>=m_form.size()) {
        //printf("bbb\n");
        return ::std::string();
    }
    now++;
    ::std::string::size_type beg = now;
    while(m_form[now]!='&'&&now<m_form.size()) now++;
    return ::std::string(m_form.c_str()+beg,now-beg);
}

Request::Request(char* buf,int buf_len)
:m_buf(buf),m_buf_len(buf_len){
    int now = 0,beg;
    while(buf[now]!=' '&&now<buf_len)now++;
    now++;
    beg = now;
    while(buf[now]!=' '&&now<buf_len)now++;
    m_url = ::std::string(buf+beg,now-beg);
    while(buf[now]!='\n'&&now<buf_len)now++;
    now++;
    while(buf[now]!='\r'&&buf[now]!='\n'&&now<buf_len){
        if(memcmp(buf+now,cookie_str,cookie_str_length) == 0){
            //printf("asdasd\n");
            now+=cookie_str_length+1;
            beg = now;
            while(buf[now]!='\r'&&buf[now]!='\n'&&now<buf_len)now++;
            m_cookie = ::std::string(buf+beg,now-beg);
        }
        while(buf[now]!='\n'&&now<buf_len)now++;
        now++;
        
    }
    while((buf[now]!='\n')&&(now<buf_len))now++;
    now++;
    if(now<buf_len){
        m_form = ::std::string(buf+now,buf_len-now);
    }
}

Request::~Request() { }