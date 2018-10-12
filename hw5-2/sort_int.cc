#include <iostream>
#include "sort.h"
using namespace std;
int main(){
    int n;
    int * arr;
    cin >> n;
    if(n<=0) return 0;
    arr=new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,n);
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
    cout << endl;
    delete[] arr;
}
