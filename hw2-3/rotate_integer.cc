#include <stdio.h>
void rotateLeft(int* pa, int* pb, int* pc){
    int tmp=*pa;
    *pa=*pb;
    *pb=*pc;
    *pc=tmp;
}

void rotateRight(int* pa, int* pb, int* pc){
    int tmp=*pc;
    *pc=*pb;
    *pb=*pa;
    *pa=tmp;
}

int main(void){
    void (*f[2])(int* pa,int* pb,int* pc) = {rotateLeft,rotateRight};
    int a=10,b=20,c=30,input=0;
    printf("%d:%d:%d\n",a,b,c);
    scanf("%d",&input);
    while(input==1||input==2){
        (*f[input-1])(&a,&b,&c);
        printf("%d:%d:%d\n",a,b,c);
        scanf("%d",&input);
    }
}
