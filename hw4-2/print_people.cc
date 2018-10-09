#include <iostream>
#include <string>
using namespace std;
struct Person{
    string name;
    int age;
};
int main(){
    int n;
    cin >> n;
    Person* arr = new Person[n];
    for(int i=0;i<n;i++) cin >> arr[i].name >> arr[i].age;
    for(int i=0;i<n;i++) cout << "Name:" << arr[i].name <<", Age:"<<arr[i].age <<endl;
    delete[] arr;
}
