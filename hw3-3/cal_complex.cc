#include <iostream>
using namespace std;
typedef struct
{
    double real;
    double cmplx;
} Complex;

void printComplex(Complex c){
    cout << c.real << " + " << c.cmplx << 'i' << endl;
}

void printAddComp(Complex a, Complex b){
    Complex c_new={a.real+b.real,a.cmplx+b.cmplx};
    printComplex(c_new);
}

void printMulComp(Complex a, Complex b){
    Complex c_new={a.real*b.real-a.cmplx*b.cmplx,a.real*b.cmplx+b.real*a.cmplx};
    printComplex(c_new);
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(6);
    Complex c[2];
    cin >> c[0].real >> c[0].cmplx;
    cin >> c[1].real >> c[1].cmplx;
    cout << "복소수1:" << endl;
    printComplex(c[0]);
    cout << "복소수2:" << endl;
    printComplex(c[1]);
    cout << "두 복소수의 합:" << endl;
    printAddComp(c[0],c[1]);
    cout << "두 복소수의 곱:" << endl;
    printMulComp(c[0],c[1]);
}
