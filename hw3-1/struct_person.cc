#include <iostream>
using namespace std;
typedef struct {
    char name[10];
    int age;
} Person;
int main(){
    Person p;
    cin >> p.name >> p.age;
    cout << "name: " << p.name << '\n' << "age: " << p.age << endl;
}
