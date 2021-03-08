#include <iostream>
#include<cstring>
using namespace std;

class Account{
private:
	int accountNumber;
	char owner[20];
	int balance;
public:
	Account()
	{	
		owner[20] = { 0 };
		balance = 0;
		accountNumber = 0;
	}
	void setOwner(char* name);
	char*  getOwner();
	void setAccountNumber(int number);
	int getAccountNumber();
	void setBalance(int amount);
	int getBalance();
	void deposit(int amount);
	void withdraw(int amount);
	void print();
};

int main()
{
	Account account1;
	cout << account1.getBalance() << endl;

	char username[20];
	int deposit = 0, withdraw = 0, accountnumber = 0;

	cin >> username >> accountnumber >> deposit >> withdraw;
	Account account2;
	account2.setOwner(username);
	account2.setAccountNumber(accountnumber);
	account2.deposit(deposit);
	account2.withdraw(withdraw);
	account2.print();
	return 0;
}
void Account::setOwner(char* name) 
{
	strcpy(owner, name);
}
char* Account:: getOwner()
{
	char* acc_name = new char[strlen(owner) + 1];
	strcpy(acc_name, owner);
	return acc_name;
}
void Account::setAccountNumber(int number)
{
	accountNumber = number;
}
int Account:: getAccountNumber()
{
	return accountNumber;
}
void Account::setBalance(int amount)
{
	balance = amount;
}
int Account::getBalance()
{
	return balance;
}
void Account::deposit(int amount)
{
	balance += amount;
}
void Account::withdraw(int amount)
{
	balance -= amount;
}
void Account::print()
{
	cout << owner << " " << accountNumber << " " << balance << endl;
}