#include<thread>
#include<assert.h>

#include "MysqlPool.h"
#include "../config/Config.h"

MysqlPool* MysqlPool::instance = nullptr;

const int SQL_CONNECT_COUTN = 3;

MysqlPool *MysqlPool::getInstance(){
   if(instance == nullptr)instance = new MysqlPool();
   return instance;
}

MysqlPool::MysqlPool(){
   for(int i = 0;i<SQL_CONNECT_COUTN;i++){
      MYSQL *sql = nullptr;
      sql = mysql_init(sql);
      if (!sql) assert(sql);
      Config*config = Config::getInstance();
      sql = mysql_real_connect(sql, "localhost",
                                 config->getDataBaseUser(), config->getDataBasePassward(),
                                 config->getDataBaseName(), 3306, NULL, 0);
      if (!sql) assert(sql);
      pool.push_back(sql);
   }
}

MYSQL* MysqlPool::get(){
   MYSQL *sql= pool[pool.size()-1];
   pool.pop_back();
   return sql;
}
void MysqlPool::free(MYSQL* m){
   pool.push_back(m);
}
