#include "simple_account.h"
void Admin::create_account(){
    int N = this->num_account;
    if(N<10){
        Account * new_account = new Account(N);
        this->account[N]= new_account;
        this->num_account++;
        cout << "Account for user " << N << " registered" << endl;
    }
}

void Admin::deposit(int id, int amount){
    if(id>=this->num_account||id<0){
        cout << "Account does not exist" << endl;
        return;
    }
    if(amount<0||(this->account[id]->balance)+amount>MAX){
        cout << "Failure: Deposit to user " << id << ' ' << amount << endl;
        return;
    }
    this->account[id]->balance+=amount;
    cout << "Success: Deposit to user " << id << ' ' << amount << endl;
}

void Admin::withdraw(int id, int amount){
    if(id>=this->num_account||id<0){
        cout << "Account does not exist" << endl;
        return;
    }
    if(amount<0||(this->account[id]->balance)-amount<0){
        cout << "Failure: Withdraw to user " << id << ' ' << amount << endl;
        return;
    }
    this->account[id]->balance-=amount;
    cout << "Success: Withdraw to user " << id << ' ' << amount << endl;
}

void Admin::transfer(int src, int dest, int amount){
    if(src>=this->num_account||dest>=this->num_account||src<0||dest<0){
        cout << "Account does not exist" << endl;
        return;
    }
    if(amount<0||(this->account[src]->balance)-amount<0||(this->account[dest]->balance)+amount>MAX){
        cout << "Failure: Transfer from user " << src << " to user " << dest << ' ' << amount << endl;
        return;
    }
    this->account[src]->balance-=amount;
    this->account[dest]->balance+=amount;
    cout << "Success: Transfer from user " << src << " to user " << dest << ' ' << amount << endl;
}

void Admin::show(int id){
    if(id>=0&&id<this->num_account){
        cout << "Balance of user "<<id<<": " << this->account[id]->balance << endl;
    }
}

int Admin::getnum_account(){
    return this->num_account;
}
