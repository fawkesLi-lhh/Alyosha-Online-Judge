#ifndef _RESPONSE_H_
#define _RESPONSE_H_

#include<map>
#include<string>

const int RESPONSER_BUFFER_HEAD_LENGTH = 2048;
const int RESPONSER_BUFFER_BODY_LENGTH = 16384;

extern ::std::string set_cookie_str;
extern ::std::string content_type;
extern ::std::string content_length;

struct ResponseBuffer{
    char head[RESPONSER_BUFFER_HEAD_LENGTH];
    int head_len;
    char body[RESPONSER_BUFFER_BODY_LENGTH];
    int body_len;
};

enum RESPONSE_TYPE{
    OK_200=1,
    NOT_FOUND_404=2,
};

class Response {
public:
    Response();
    ~Response();

    void setHead(const ::std::string &key,const ::std::string &value){
        m_map[key] = value;
    }

    template<typename T>
    void setBody(T&& body){
        m_body = ::std::forward<T>(body);
    }

    void generateResponse(ResponseBuffer* buffer);
private:
    int m_type;
    ::std::map<::std::string,::std::string> m_map;
    ::std::string m_body;
};




#endif 
