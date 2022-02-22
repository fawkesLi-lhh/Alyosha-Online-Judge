#include<string.h>
#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#include "Master.h"
#include "HttpStatus.h"

void endServer(){ }
void beginServer(){}
int endPost(EventPackage* event){}

void filterHttpStatus(HttpStatus* status){
    
}

int doPost(EventPackage* event,HttpStatus* status){
    return 0;
}

signed main(){
    Master master;
    master.beginMaster(9856);

    
    return 0;
}