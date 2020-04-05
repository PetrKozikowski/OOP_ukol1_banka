#include <iostream>
#include <string>
#include "client.h"
#include "Account.h"


using namespace std;

Account::Account()
{
}


Account::Account(int n, Client *c)
{
	number = n;
	owner = c;

}


Account::Account(int n, Client* c, double ir)
{
	number = n;
	owner = c;
	interestRate = ir;

}

Account::Account(int n, Client* c, Client* p)
{
	number = n;
	owner = c;
	partner = p;

}

Account::Account(int n, Client* c, Client* p, double ir)
{
	number = n;
	owner = c;
	partner = p;
	interestRate = ir;
}

Account::~Account()
{
}

int Account::GetNumber()
{
	return number;
}

Client* Account::GetOwner()
{
	return owner;
}

Client* Account::GetPartner()
{
	return partner;
}

double Account::GetInterestRate()
{
	return interestRate;
}

double Account::GetBalance()
{
	return balance;
}

bool Account::CanWithdraw(double a)
{
	if (a > balance)
	{
		cout << "Nedostatek penez!" << " Stav uctu: " << balance << endl;
		return false;
	}
	cout << "Muzes vybrat: " << balance << endl;
	return true;
}

void Account::Deposit(double a)
{
	balance += a;
	cout << "Vlozeno: " << a << " Stav uctu: " << balance << endl;
}

bool Account::Withdraw(double a)
{
	if (CanWithdraw(a) == true)
	{
		balance -= a;
		cout << "Vybrano: " << a << " Stav uctu: " << balance << endl;
		return true;
	}
	cout << "Nelze vybrat!" << " Stav uctu: " << balance << endl;
	return false;
}

void Account::AddInterest()
{
	balance += balance * interestRate / 100;
}