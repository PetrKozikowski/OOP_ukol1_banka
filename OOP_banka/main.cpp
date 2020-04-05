#include <iostream>
#include "client.h"
#include "Account.h"
#include "Bank.h"

using namespace std;


int main()
{
	int a;
	const int NAME_COUNT = 10;
	const double INTEREST_RATE = 1.5;
	bool st;

	string prijmeni[NAME_COUNT] = {
		"Bjornsson",
		"Hall",
		"Shaw",
		"Stoltman",
		"Carter",
		"Kramer",
		"Jagger",
		"Jenkins",
		"Jones",
		"Jackson"
	};
		
	string jmeno[NAME_COUNT] = {
		"Peter",
		"Curtis",
		"Frank",
		"John",
		"Radim",
		"Mark",
		"Ferdinand",
		"Robert",
		"Ethan",
		"Ramon"
	};

	const int b1_clients_count = NAME_COUNT * NAME_COUNT;
	const int b1_accounts_count = NAME_COUNT * NAME_COUNT;
	Client* b1_clients[b1_clients_count]{};
	Account* b1_accounts[b1_accounts_count]{};
	Client* client1, * client2;
	Account* account1, * account2;

	Bank* bank1 = new Bank{ b1_clients_count, b1_accounts_count };
	// Vytvoøení sta klientù a sta úètù.
	for (int i = 0; i < NAME_COUNT; i++)
	{
		if (i == 2)
		{
			i = i * 2 / 2;

		}
		for (int j = 0; j < NAME_COUNT; j++)
		{
			string s1 = jmeno[j] + ' ' + prijmeni[i];
			string s2 = jmeno[(j + 1) % 10] + ' ' + prijmeni[i];
			b1_clients[10 * i + j] = bank1->CreateClient(1000 + 10 * i + j, s1);
			if (10 * i + j != 0)
			{
				b1_accounts[10 * i + j] = bank1->CreateAccount(50000 + 10 * i + j, b1_clients[10 * i + j], b1_clients[10 * i + j - 1], INTEREST_RATE);
			}
			else
			{
				b1_accounts[10 * i + j] = bank1->CreateAccount(50000 + 10 * i + j, b1_clients[10 * i + j], INTEREST_RATE);
			}
		}

	}
	cout << endl;
	cout << "*** Pokus o vytvoreni uctu do plneho seznamu ***" << endl;
	account2 = bank1->CreateAccount(5, b1_clients[59]);

	cout << endl;
	cout << "*** Pokus o vlozeni klienta do plneho seznamu ***" << endl;
	client2 = bank1->CreateClient(5, "Petr Kozikowski");

	// Testování funkce GetClient
	cout << endl;
	cout << "*** Testovani funkce GetCode ***" << endl;
	client1 = bank1->GetClient(1050);
	cout << "client1 name: " << client1->GetName() << "  client1 code: " << client1->GetCode() << endl; 

	// Testování funkce GetAccount
	cout << endl;
	cout << "*** Testovani funkce GetAccount ***" << endl;
	account1  = bank1->GetAccount(50050);
	if (account1->GetOwner() != nullptr && account1->GetPartner() != nullptr)
	{
		cout << "account1 owner: " << account1->GetOwner()->GetName() << "  account1 partner: " << account1->GetPartner()->GetName() << endl;
		cout << "account1 number: " << account1->GetNumber() << "  account1 balance: " << account1->GetBalance() << "  account1 interestrate: " << account1->GetInterestRate() << endl;
	}
	cout << "*** Vkladame castku 1000 ***" << endl;
	account1->Deposit(1000.);
	cout << "*** Lze vybrat 500? ***" << endl;
	st = account1->CanWithdraw(500.);
	cout << "*** Lze vybrat 1500? ***" << endl;
	st = account1->CanWithdraw(1500.);
	cout << "*** Pokus o vyssi vyber - 1500 ***" << endl;
	st = account1->Withdraw(1500.);
	cout << "*** Pokus o vyber - 700 ***" << endl;
	st = account1->Withdraw(700.);
	cout << "*** Pridani uroku ***" << endl;
	bank1->AddInterest();
	cout << "Stav uctu: " << account1->GetBalance() << endl;

	
	delete bank1;


	return 0;

}