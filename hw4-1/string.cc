#include <iostream>
#include <string>
using namespace std;
int main(){
    string fst,snd;
    cin >> fst;
    cin >> snd;
    string m;
    m=fst+snd;
    cout<<m<<'\n'<<m[0]<< '\n' <<m[m.size()-1] << endl;
}
