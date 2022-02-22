#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include"Tire.h"

//default
const int DEFAULT_FILE_NAME_COUNT = 300;

enum FileType{
    FILE_TYPE_NULL = 0,
    FILE_TYPE_FD=1,
    FILE_TYPE_BUFFER=2,
    FILE_TYPE_BUFFER_MMAP=3,
};

struct FileNode{
    int len;
    int fd;
    int flag;
    char* data;
};

class FileHandler{
public:
    void initHander();

    void endHander();

    FileNode processUrl(char* str,int len);

private:
    void ReadDir(char * path);
private:
    Tire tire;
};




#endif

