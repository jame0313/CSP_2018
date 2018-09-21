#include <iostream>
using namespace std;

typedef struct
{
    int xpos;
    int ypos;
}Point;

Point getScale2xPoint(const Point* p){
    Point p_new={p->xpos*2,p->ypos*2};
    return p_new;
}

void swapPoint(Point& p1, Point& p2){
    Point tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main(){
    Point p1,p2;
    cin >> p1.xpos >> p1.ypos;
    p2 = getScale2xPoint(&p1);
    cout << "Calling getScale2xPoint()" << endl;
    cout << "p1 : "<< p1.xpos << ' ' << p1.ypos << endl;
    cout << "p2 : "<< p2.xpos << ' ' << p2.ypos << endl;
    swapPoint(p1,p2);
    cout << "Calling swapPoint()" << endl;
    cout << "p1 : "<< p1.xpos << ' ' << p1.ypos << endl;
    cout << "p2 : "<< p2.xpos << ' ' << p2.ypos << endl;
}
