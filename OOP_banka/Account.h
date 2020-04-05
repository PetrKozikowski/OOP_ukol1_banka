#pragma once
//#include "client.h"

class Account
{
private:
	int number;
	double balance;
	double interestRate;

	Client* owner;
	Client* partner;
public:
	Account();
	Account(int n, Client* c);
	Account(int n, Client* c, double ir);
	Account(int n, Client* c, Client* p);
	Account(int n, Client* c, Client* p, double ir);
	~Account();

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client *GetOwner();
	Client *GetPartner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();

};

