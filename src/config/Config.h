#ifndef _CONFIG_H_
#define _CONFIG_H_

const int CONFIG_BUFFER_COUNT = 555;

class Config
{
public:
   static Config*getInstance();
   int getPort();
   char *getDataBaseUser();
   char *getDataBasePassward();
   char *getDataBaseName();
private:
   static Config* instance;
   Config();
private:
   int port;
   char db_user[CONFIG_BUFFER_COUNT];
   char db_passwd[CONFIG_BUFFER_COUNT];
   char db_name[CONFIG_BUFFER_COUNT];
};




#endif 
