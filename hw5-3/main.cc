#include <iostream>
#include <cstdlib>
#include "magic_square.h"
using namespace std;
int main(int argc, char * argv[]){
    if(argc<2) return 0;
    int n=atoi(argv[1]);
    if(n<3||n%2==0) return 0;
    int ** arr = new int* [n];
    for(int i=0;i<n;i++) arr[i]= new int[n];
    make_square(arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout << arr[i][j] << ' ';
        cout << endl;
    }
    for(int i=0;i<n;i++) delete[] arr[i];
    delete[] arr;
}
