#include <iostream>
using namespace std;

class pr{
private:

int account_number;
int balance;

public:
void setAccount_number(int a){
    account_number=a;
}

int getAccount_number(){
    return account_number;
}


void setBalance(int b){
    balance=b;
}

int getBalance(){
    return balance;
}


};

int main(){

pr r;
r.setAccount_number(890);
r.setBalance(20000);

cout<<"Account number:"<<r.getAccount_number()<<endl;
cout<<"Balance:"<<r.getBalance()<<endl;

    return 0;
}
