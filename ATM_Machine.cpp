#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

void showBalance(double balance) {
    cout << fixed << setprecision(2);
    cout << "My current balance is: $" << balance << endl;
}

double depositBalance(double balance) {
    double depositamount;
    cout << "Enter amount of deposit: ";
    cin >> depositamount;
    if (depositamount > 0) {
        balance += depositamount;
    } else {
        cout << "No negative value is supported.\n";
    }

    return balance;
}

double withdrawBalance(double balance) {
    double withdrawamount;
    cout << "Enter amount of Withdraw: ";
    cin >> withdrawamount;

    if (withdrawamount > 0 && withdrawamount <= balance) {
        balance -= withdrawamount;
    } else {
        cout << "Invalid withdrawal amount! Check your balance.\n";
    }
    return balance;
}

bool sendOTP() {
    srand(time(0));
    int otpcreate = rand() % 900000 + 100000; 
    cout << "An OTP is sent to your registered phone number: " << otpcreate << endl;

    int userotp;
    cout << "Enter the OTP to reset your password: ";
    cin >> userotp;
    if (userotp == otpcreate) {
        return true;
    } else {
        return false;
    }
}

bool forgotpass(string &pin, string registeredPhone) {
    string phonenumber;
    cout << "You have selected 'Forgot Password'. Please enter your registered phone number: ";
    cin >> phonenumber;

   
    if (phonenumber == registeredPhone) {  
        cout << "Phone number verified. Sending OTP to this phone number.....\n";
        if (sendOTP()) {
            cout << "OTP verified successfully.\n";
            cout << "Please Enter a new PIN: ";
            cin >> pin;
            cout << "Your PIN has been reset successfully!\n";
            return true;
        } else {
            cout << "Incorrect OTP. Unable to reset your PIN.\n";
            return false;
        }
    } else {
        cout << "Phone number not recognized.\n";
        return false;
    }
}

struct Account {
    string accountName;
    double balance;
    string pin;
    string phoneNumber;  
};

vector<Account> accounts;

void createAccount() {
    Account newAccount;
    cout << "Enter account name:";
    cin >> newAccount.accountName;
    cout << "Enter a PIN for your account: ";
    cin >> newAccount.pin;
    cout << "Enter your phone number: ";
    cin >> newAccount.phoneNumber;  
    newAccount.balance = 0.0; 
    accounts.push_back(newAccount);
    cout << "Account created successfully!\n";
}

Account selectAccount() {
    string accountName;
    cout << "Enter your account name to access: ";
    cin >> accountName;
    
    for (auto& acc : accounts) {
        if (acc.accountName == accountName) {
            return acc;
        }
    }
    cout << "Account not found!\n";
    Account emptyAccount = {}; 
    return emptyAccount;
}

int main() {
    int choice;

    while (true) {
        cout << "1. Register a new account\n";
        cout << "2. Login to an existing account\n";
        cout << "3. Exit\n";
        cout << "Choose any option: ";
        cin >> choice;

        if (choice == 1) {
            createAccount();
        } else if (choice == 2) {
            Account currentAccount = selectAccount();
            if (currentAccount.accountName == "") {
                continue; 
            }

            string inputpin;
            cout << "Enter your PIN: ";
            cin >> inputpin;

            int attempts = 3;

            while (inputpin != currentAccount.pin && attempts > 0) {
                cout << "Invalid PIN. You have " << attempts << " attempt(s) remain.\n";
                cout << "Do you want to reset your PIN? (yes/no): ";
                string resetOption;
                cin >> resetOption;
                if (resetOption == "yes" || resetOption == "Yes") {
                    if (forgotpass(currentAccount.pin, currentAccount.phoneNumber)) {
                        break;
                    } else {
                        cout << "Try again later.\n";
                        return 1;
                    }
                } else {
                    cout << "Enter your PIN: ";
                    cin >> inputpin;
                }

                attempts--;
            }

            if (inputpin != currentAccount.pin && attempts == 0) {
                cout << "Too many failed attempts. Access denied.\n";
                continue;
            }

            cout << "----------------------------------------------------\n";
            cout << "                Bank System                         \n";
            cout << "----------------------------------------------------\n";

            int actionChoice;
            do {
                cout << "1. Balance check.\n";
                cout << "2. Deposit Balance.\n";
                cout << "3. Withdraw Balance.\n";
                cout << "4. Exit\n";
                cout << "Choose any option: ";
                cin >> actionChoice;
                
                switch (actionChoice) {
                    case 1:
                        showBalance(currentAccount.balance);
                        break;
                    case 2:
                        currentAccount.balance = depositBalance(currentAccount.balance);
                        cout << fixed << setprecision(2);
                        cout << "My Deposit balance is: $" << currentAccount.balance << endl;
                        break;
                    case 3:
                        currentAccount.balance = withdrawBalance(currentAccount.balance);
                        cout << fixed << setprecision(2);
                        cout << "After withdrawal my balance is: $" << currentAccount.balance << endl;
                        break;
                    case 4:
                        cout << "THANK YOU FOR USING OUR SYSTEM!\n";
                        return 0;
                    default:
                        cout << "Invalid option. Please try again!..\n";
                        break;
                }
            } while (actionChoice != 4);
        } else if (choice == 3) {
            cout << "Thank you for using our system!\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}








  
 ...........................................code 2.....................................................................

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







...........................................code 3.....................................................................




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
