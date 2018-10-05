#include <iostream>
#include <string>
using namespace std;
int add(int a,int b){
    return a+b;
}

string add(string a, string b){
    return a+string("-")+b;
}

int main(){
    int i_a,i_b;
    string s_a,s_b;
    cin >> i_a >> i_b >> s_a >> s_b;
    cout << add(i_a,i_b) << endl;
    cout << add(s_a,s_b) << endl;
}
    
