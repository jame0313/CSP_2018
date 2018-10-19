#include "reply_admin.h"
#include <cstdlib>
ReplyAdmin admin;
int main(){
    string inputs;
    admin.addChat(string("Hello, Reply Administartor!"));
    admin.addChat(string("I will be a good programmer."));
    admin.addChat(string("This class is awesome."));
    admin.addChat(string("Professor Lim is wise."));
    admin.addChat(string("Two TAs are kind and helpful."));
    admin.addChat(string("I think male TA looks cool."));
    while(getline(cin,inputs),inputs!="#quit"){
        if(inputs.length()>=7&&inputs.substr(0,7)=="#remove"){
            if(inputs.find(",")!=string::npos){
                int cnt=1;
                for(int i=8;i<inputs.length();i++) if(inputs[i]==',') cnt++;
                int* arr=new int[cnt];
                for(int i=8,pre=8,idx=0;i<inputs.length();i++){
                    if(inputs[i]==','){
                        arr[idx++]=atoi(inputs.substr(pre,i-pre+1).c_str());
                        pre=i+1;
                    }
                    if(i==inputs.length()-1){
                        arr[idx++]=atoi(inputs.substr(pre,i-pre+1).c_str());
                        admin.removeChat(arr,idx);
                    }
                }
                delete[] arr;
            }
            else{
            int cnt=0;
            for(int i=8;i<inputs.length();i++) if(inputs[i]=='-') cnt++;
            if(cnt>0&&!(cnt==1&&inputs[8]=='-')){
                int _start,_end;
                if(cnt==1){
                    int idx=inputs.find("-");
                    _end=atoi(inputs.substr(idx+1).c_str());
                    _start=atoi(inputs.substr(8,idx-7).c_str());
                }
                else if(cnt==2){
                    if(inputs[8]=='-'){
                        int idx=inputs.substr(9).find("-");
                        _end=atoi(inputs.substr(idx+1).c_str());
                        _start=atoi(inputs.substr(8,idx-7).c_str());
                    }
                    else{
                        int idx; 
                        for(int i=8;i<inputs.length();i++){
                            if(inputs[i]=='-'){
                                idx=i;
                                break;
                            }
                        }
                        _end=atoi(inputs.substr(idx+1).c_str());
                        _start=atoi(inputs.substr(8,idx-7).c_str());                
                    }
                }
                else{
                    int idx; 
                        for(int i=9;i<inputs.length();i++){
                            if(inputs[i]=='-'){
                                idx=i;
                                break;
                            }
                        }
                        _end=atoi(inputs.substr(idx+1).c_str());
                        _start=atoi(inputs.substr(8,idx-7).c_str()); 
                }
                admin.removeChat(_start,_end);
            }
            else{
                int _index=atoi(inputs.substr(8).c_str());
                admin.removeChat(_index);
            }
        }    
        }
        else{
            admin.addChat(inputs);
        }
        admin.show();        
    }
}
