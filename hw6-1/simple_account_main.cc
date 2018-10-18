#include "simple_account.h"
int main(){
    char Q;
    Admin admin;
    while(cout <<"Job?"<<endl, cin>>Q ,Q!='Q'){
        if(Q=='N'){
            int N=admin.getnum_account();
            admin.create_account();
            admin.show(N);
        }
        else if(Q=='D'){
            int id,amount;
            cin >> id >> amount;
            admin.deposit(id,amount);
            admin.show(id);
        }
        else if(Q=='W'){
            int id,amount;
            cin >> id >> amount;
            admin.withdraw(id,amount);
            admin.show(id);
        }
        else if(Q=='T'){
            int src,dest,amount;
            cin >> src >> dest >> amount;
            admin.transfer(src,dest,amount);
            admin.show(src<dest?src:dest);
            admin.show(src>dest?src:dest);
        }
    }
}
