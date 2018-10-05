#include <iostream>
using namespace std;
int main(){
    int * arr;
    int n;
    cin >> n;
    arr = new int[n];
    int min,max;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i==0) min=max=arr[i];
        else{
            min=min<arr[i]?min:arr[i];
            max=max>arr[i]?max:arr[i];
        }
    }
    cout << "min: " << min << '\n' << "max: " << max << endl;
    delete[] arr;
}
