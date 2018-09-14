#include <stdio.h>
int main(){
    char txt[10]={0,};
    scanf("%s",txt);
    for(int i=0;txt[i]!=0;i++){
        if(txt[i]<='Z') txt[i]+='a'-'A';
        else txt[i]-='a'-'A';
    }
    printf("%s\n",txt);
}
