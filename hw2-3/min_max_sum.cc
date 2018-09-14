#include <stdio.h>
int main(){
    int min,max,sum,arr[5];
    for(int i=0;i<5;i++){
        scanf("%d",arr+i);
        if(i==0) min=max=sum=arr[i];
        else{
            min=min<arr[i]?min:arr[i];
            max=max>arr[i]?max:arr[i];
            sum+=arr[i];
        }
    }
    printf("min: %d\nmax: %d\nsum: %d\n",min,max,sum);
    return 0;
}
