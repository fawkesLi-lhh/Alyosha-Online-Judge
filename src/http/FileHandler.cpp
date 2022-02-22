#include "FileHandler.h"

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>

void FileHandler::initHander(){
    tire.initTire();
    char path[1111] = "assets";
    ReadDir(path);
}

void FileHandler::ReadDir(char * path){
    DIR *dir; dirent *ptr;int path_len = strlen(path);
    if ((dir=opendir(path)) == NULL){
        perror("Open dir error...");
        exit(1);
    }
    while ((ptr=readdir(dir)) != NULL){
        if(ptr->d_name[0] == '.') continue;
        strcat(path,"/");
        strcat(path,ptr->d_name);
        if(ptr->d_type == 8) {
            struct stat file_stat;
            stat(path,&file_stat);
            FileNode *file = new FileNode();
            memset(file,0,sizeof(FileNode));
            file->flag = FILE_TYPE_BUFFER_MMAP;
            file->fd = open(path,O_RDONLY);
            file->len = file_stat.st_size;
            file->data = (char*)mmap(0,file->len,PROT_READ,MAP_SHARED,file->fd,0);
            int flag = tire.insertString(path+6,strlen(path+6),(long long)file);
            if(flag == 0){
                printf("too many File\n");
                exit(0);
            }
        }
        if(ptr->d_type == 4) ReadDir(path);
        path[path_len] = '\0';
   }
   closedir(dir);
}

void FileHandler::endHander(){
    tire.endTire();
}

FileNode FileHandler::processUrl(char* str,int len){
    if(len == 0)len = DEFAULT_FILE_NAME_COUNT;
    FileNode *file = (FileNode*)tire.findString(str,&len);
    if(file == NULL) return FileNode{0,0,0,0};
    return *file;
}


