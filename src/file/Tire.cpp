#include"Tire.h"

#include<string.h>

void Tire::initTire(){
    data = new TireNode[TIRE_MAX_COUNT];
    memset(data,0,sizeof(TireNode)*TIRE_MAX_COUNT);
    cnt = 1;
}
    
void Tire::endTire(){
    delete[] data;
}

int Tire::insertString(const char *str,int len,long long flag){
    if(cnt+len>=TIRE_MAX_COUNT)return 0;
    int now = 0;
    for(int i = 0;i<len;i++){
        if(data[now].next[(int)str[i]] == 0)
            data[now].next[(int)str[i]] = cnt++;
        now = data[now].next[(int)str[i]];
    }
    data[now].flag = flag;
    return 1;
}

long long Tire::findString(const char* str,int *len)const{
    int now = 0;
    for(int i = 0;i<*len;i++){
        if((int)str[i]>127||(int)str[i]<0)return 0;
        if(str[i] == ' '||str[i] == '\n'||str[i] == '\0'||str[i] == '\r'){
            *len = i;
            break;
        }
        if(data[now].next[(int)str[i]] == 0)return 0;
        now = data[now].next[(int)str[i]];
    }
    return data[now].flag;
}
