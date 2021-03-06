#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <string>

class HttpRequest {
public:
    HttpRequest(char* buf,int buf_len);
    virtual ~HttpRequest();

    ::std::string findParameter(::std::string str);

public:
    ::std::string m_url;
    ::std::string m_cookie;
    ::std::string m_form;
private:
    char* m_buf;
    int m_buf_len;
};

#endif

