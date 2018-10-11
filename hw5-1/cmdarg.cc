#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main(int argc, char * argv[]){
    int sum=0;
    string s;
    for(int i=1;i<argc;i++){
        if(atoi(argv[i])!=0){
            sum+=atoi(argv[i]);        
        }
        else s+=argv[i];
    }
    cout << s << '\n' << sum << endl;
}
