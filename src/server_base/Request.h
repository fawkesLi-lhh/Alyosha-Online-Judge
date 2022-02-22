#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <string>

class Request {
public:
    Request(char* buf,int buf_len);
    ~Request();

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

