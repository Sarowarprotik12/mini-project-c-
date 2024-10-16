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