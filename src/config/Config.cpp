#include"Config.h"

#include<fstream>
#include<string>
#include<thread>
#include <string.h>

Config* Config::instance = nullptr;

Config::Config(){
   std::ifstream fin("config.txt");
   std::string name;
   memset(db_user,0,CONFIG_BUFFER_COUNT);
   memset(db_passwd,0,CONFIG_BUFFER_COUNT);
   memset(db_name,0,CONFIG_BUFFER_COUNT);
   fin>>name>>port;
   fin>>name>>db_user;
   fin>>name>>db_passwd;
   fin>>name>>db_name;
   fin.close();
}

Config* Config::getInstance(){
   if(instance == nullptr) instance = new Config();
   return instance;
}

int Config::getPort(){
   return port;
}
char *Config::getDataBaseUser(){
   return db_user;
}
char *Config::getDataBasePassward(){
   return db_passwd;
}
char *Config::getDataBaseName(){
   return db_name;
}
