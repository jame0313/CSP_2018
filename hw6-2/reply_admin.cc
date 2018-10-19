#include "reply_admin.h"
int ReplyAdmin::getChatCount(){
    int idx=0;
    while(idx<NUM_OF_CHAT&&this->chats[idx]!="") idx++;
    return idx;
}

bool ReplyAdmin::addChat(string _chat){
    int idx=getChatCount();
    if(idx>=NUM_OF_CHAT) return false;
    this->chats[idx] = _chat;
    return true;
}

bool ReplyAdmin::removeChat(int _index){
    int idx=getChatCount();
    if(0<=_index&&_index<idx){
        for(int i=_index;i<idx-1;i++){
            this->chats[i]=this->chats[i+1];
        }
        this->chats[idx-1]="";
        return true;
    }
    return false;
}

bool ReplyAdmin::removeChat(int _start, int _end){ 
    int idx=getChatCount();
    if(_start>_end) return false;
    if(0<=_end&&_start<idx){
        bool iswork = false;
        int cnt=0;
        for(int i=(_start>=0?_start:0);i<=(_end<=idx?_end:idx);i++){
            bool ret = 0<=i&&i<idx;
            if(ret) this->chats[i]="",cnt++;
            iswork=ret==true?true:iswork;
        }
        for(int i=0;i<cnt;i++){
            for(int j=0;j<idx-1-i;j++){
                if(this->chats[j]==""){
                    if(this->chats[j+1]!=""){
                        this->chats[j]=this->chats[j+1];
                        this->chats[j+1]="";
                    }
                }
            }
        }
        return iswork;
    }
    return false;
}
bool ReplyAdmin::removeChat(int* _indices,int _count){
    bool iswork=false;
    int idx=getChatCount();
    for(int i=0;i<_count;i++){
        bool ret = 0<=_indices[i]&&_indices[i]<idx;
        if(ret) this->chats[_indices[i]]="";
        iswork= ret==true?true:iswork;
    }
    for(int i=0;i<_count;i++){
        for(int j=0;j<idx-1-i;j++){
            if(this->chats[j]==""){
                if(this->chats[j+1]!=""){
                    this->chats[j]=this->chats[j+1];
                    this->chats[j+1]="";
                }
            }
        }
    } 
    return iswork;
}
void ReplyAdmin::show(){
    int n=getChatCount();
    for(int i=0;i<n;i++){
        cout << i << ' ' << chats[i] << endl;
    }
}
