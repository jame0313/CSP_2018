#include <iostream>
#define MAX 1000000
using namespace std;
class Account{
    public:
        int id;
        int balance;
        Account(int N): id(N), balance(0) {}
};

class Admin{
    private:
        Account * account[10];
        int num_account;
    public:
        Admin(): num_account(0) {}
        void create_account();
        void deposit(int id, int amount);
        void withdraw(int id, int amount);
        void transfer(int src, int dest, int amount);
        void show(int id);
        int getnum_account();
};
