#include <iostream>
using namespace std;
typedef struct
{
    char name[7];
    int score;
}Person;

void printScoreStars(Person* persons, int len){
    for(int i=0;i<len;i++){
        cout << (persons+i)->name << ' ';
        for(int j=0;j<(persons+i)->score/5;j++) putchar('*');
        putchar('\n');
    }
}

int main(){
    Person p[3];
    for(int i=0;i<3;i++) cin >> (p+i)->name >> (p+i)->score;
    printScoreStars(p,3);
}
