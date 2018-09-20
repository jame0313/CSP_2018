#include <iostream>
using namespace std;
typedef struct {
    char name[10];
    int age;
} Person;
int main(){
    Person p[3];
    for(int i=0;i<3;i++) cin >> (p+i)->name >> (p+i)->age;
    for(int i=0;i<3;i++) cout << "Name:"<<(p+i)->name <<", Age:"<< (p+i)->age << endl;
}
