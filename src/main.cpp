#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <string>
#include <iostream>

#include "Master.h"
#include "Config.h"

#include "EventPackage.h"
#include "HttpStatus.h"

using namespace std;



signed main(){
    Master master;
    master.beginMaster(
        Config::getInstance()->getPort());

    return 0;
}