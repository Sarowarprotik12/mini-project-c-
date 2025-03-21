#include <bits/stdc++.h>
using namespace std;
class atm {
private:
	double balance;
public:

	atm(double b): balance(b) {}

	void balanceshow() {
		cout<<"Your Balance : $"<<balance<<endl;
	}

	void deposit(double amount) {

		if(amount>0) {
			balance+=amount;
			cout<<"You have Deposited: $"<<amount<<endl;
		} else {
			cout<<"Invalid Deposit Balance."<<endl;
		}

	}


	void withdraw(double amount) {

		if(amount>0 && amount<=balance) {
			balance-=amount;
			cout<<"You have Withdrawn: $"<<amount<<endl;
		} else {
			cout<<"Insufficient funds."<<endl;
		}

	}


};

int main()
{
	string pin="1234";
	string inputpin;

	cout << "Enter your PIN: ";
	cin >>inputpin;
	if(inputpin!=pin) {
		cout << "Invalid PIN. Access denied." << endl;
		return 1;
	}

	atm a(1000);




	int choice;

	do {
		cout << "\nATM Menu:\n";
		cout << "1. Check Balance\n";
		cout << "2. Deposit Money\n";
		cout << "3. Withdraw Money\n";
		cout << "4. Exit\n";
		cout << "Choose an option: ";
		cin >> choice;
		double amount;


		switch(choice) {

		case 1:
			a.balanceshow();
			break;

		case 2:
			cout<<"Enter deposit amount:";
			cin>>amount;
			a.deposit(amount);
			break;

		case 3:
			cout<<"Enter withdraw balance:";
			cin>>amount;
			a.withdraw(amount);
			break;

		case 4:
			cout << "Thank you for using the ATM. Goodbye!" <<endl;
			break;

		default:
			cout<<"Invalid choice.Please try agin."<<endl;



		}

	} while (choice != 4);




	return 0;
}







               another way code::::::::::::::::::::::::





#include <iostream>
#include <iomanip>
using namespace std;

void showBalance(double balance){
  cout << fixed << setprecision(2);
  cout<<"My current balance is:"<<"$"<<balance<<endl;
}
double depositBalance(double balance){
    double depositamount;
    cout<<"Enter amount of deposit:";
    cin>>depositamount;
    if(depositamount>0){
      balance+=depositamount;
    }else {
      cout<<"No negative value is supported.\n";
    }
   
    return balance;
    
}
double withdrawBalance(double balance){
    double withdrawamount;
    cout<<"Enter amount of Withdraw:";
    cin>>withdrawamount;
    
     if (withdrawamount > 0 && withdrawamount<= balance) {
      balance -= withdrawamount;
  } else {
      cout << "Invalid withdrawal amount! Check your balance.\n";
  }
    return balance;
    
}







int main() 
{
    double balance=200.00;
    string pin="123";
    string inputpin;
    cout<<"Enter your pin:";
    cin>>inputpin;
    if(inputpin!=pin){
    	cout << "Invalid PIN. Access denied." << endl;
		return 1;
	}

    
cout<<"----------------------------------------------------\n";
cout<<"                Bank System                         \n";
cout<<"----------------------------------------------------\n";

int choice;
do {
cout<<"1.Balance cheak.\n";
cout<<"2.Deposit Balance.\n";
cout<<"3.Withdraw Balance.\n";
cout<<"4.Exit\n";
cout<<"Choose any option:";
cin>>choice;
switch(choice){
    case 1:
    showBalance(balance);
    break;
    case 2: balance=depositBalance(balance);
     cout << fixed << setprecision(2);
    cout << "My Deposit balance is: $" << balance << endl;
    break;
    case 3: balance=withdrawBalance(balance);
     cout << fixed << setprecision(2);
    cout << "After withdraw my balance is: $" << balance << endl;
    break;
    case 4:  cout << "THANK YOU FOR USING OUR SYSTEM!\n";
                return 0;
    default:cout<<"Invalid option.please try again!..\n";
             cout<<"THANKS FOR USING OUR SYSTEM..\n";
    
}    
}while (choice != 4);

    return 0;
}
