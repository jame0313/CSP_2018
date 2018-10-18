#include <iostream>
#include "simple_shape.h"
using namespace std;

int main(){
    char Q;
    while(cout<<"shape?"<<endl, cin>>Q , Q!='Q'){
        if(Q=='C'){
            Circle *circle=new Circle;
            double x,y,radius;
            cin >> x >> y >> radius;    
            circle->setpos(x,y,radius);
            cout <<"area: " << circle->getarea() << ", perimeter: " << circle->getperimeter() << endl;
            delete circle;
        }
        else if(Q=='R'){
            Rectangle *rectangle=new Rectangle;
            double left,top,right,bottom;
            cin >> left >> top >> right >> bottom;
            rectangle->setpos(left,top,right,bottom);
            cout <<"area: " << rectangle->getarea() << ", perimeter: " << rectangle->getperimeter() << endl;
            delete rectangle;
        }
    }
}
