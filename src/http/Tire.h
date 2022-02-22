#ifndef _TIRE_H_
#define _TIRE_H_

const int TIRE_MAX_COUNT = 8192;

struct TireNode{
    long long flag;
    int next[128];
};

class Tire{
public:
    void initTire();
    
    void endTire();

    int insertString(const char *str,int len,long long flag);

    long long findString(const char* str,int *len) const;
private:
    TireNode *data;
    int cnt;
};


#endif
