#include <stdio.h>
void square(double * x){
    *x=(*x)*(*x);
}
int main(){
    double dvar;
    scanf("%lf",&dvar);
    square(&dvar);
    printf("%lf\n",dvar);
}
