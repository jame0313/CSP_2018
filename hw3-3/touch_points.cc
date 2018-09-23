#include <iostream>
using namespace std;
typedef struct
{
    double x;
    double y;
} Point;

typedef struct
{
    char name[7];
    Point points[3];
} Person;

double dist(double x, double y){
    return x*x+y*y;
}
int main(){
    Person p1,p2,p3;
    Person *p[3] ={&p1,&p2,&p3};
    int mx_i[3];
    for(int i=0;i<3;i++){
        cin >> (*(p+i))->name;
        double mx=-1;
        for(int j=0;j<3;j++){
            cin >> (*(p+i))->points[j].x >> (*(p+i))->points[j].y;
            if(mx<dist((*(p+i))->points[j].x, (*(p+i))->points[j].y)){
                mx=dist((*(p+i))->points[j].x, (*(p+i))->points[j].y);
                mx_i[i]=j;
            }
            
        }
    }
    for(int i=0;i<3;i++){
        cout << (*(p+i))-> name << " (" << (*(p+i))->points[mx_i[i]].x << ", " << (*(p+i))->points[mx_i[i]].y << ')' << endl;
    }
}
