#include <iostream>
#include "circle.h"
using namespace std;
int main(){
    cout<<fixed;
    cout.precision(6);
    double r;
    cin >> r;
    cout << "Perimeter: " << getCirclePerimeter(r) << endl;
    cout << "Area: " << getCircleArea(r) << endl;
}
