#ifndef _RESPONSE_H_
#define _RESPONSE_H_

#include"EventPackage.h"

#include<map>
#include<string>

extern ::std::string set_cookie_str;
extern ::std::string content_type_str;
extern ::std::string content_length;

extern ::std::string application_json_str;

enum RESPONSE_TYPE{
    OK_200=1,
    NOT_FOUND_404=2,
};

class HttpResponse {
public:
    HttpResponse();
    virtual ~HttpResponse();

    void setHead(const ::std::string &key,const ::std::string &value){
        m_map[key] = value;
    }

    template<typename T>
    void setBody(T&& body){
        m_body = ::std::forward<T>(body);
    }

    void generateResponse(EventPackage* event);
private:
    int m_type;
    ::std::map<::std::string,::std::string> m_map;
    ::std::string m_body;
};




#endif 
