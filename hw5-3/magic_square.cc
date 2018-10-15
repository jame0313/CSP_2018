#include "magic_square.h"
void make_square(int ** arr, const int len){
    int idx=1;
    int x=0,y=len/2;
    arr[x][y]=idx++;
    while(true){
        if(idx>len*len) break;
        x--,y++;
        y=(y+len)%len;
        x=(x+len)%len;
        if(arr[x][y]==0) arr[x][y]=idx++;
        else x+=3,y-=2;
    }
}
