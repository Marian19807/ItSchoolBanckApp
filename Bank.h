


#pragma once
#include"ContBancar.h"
#include<vector>
#include<iostream>
#include<string>
#include <string>
class Bank
{
	std::vector<ContBancar*> m_ConturiBancare;
	
	std::string createIban();
public:
	Bank();
	bool schimbare ;
	bool testNume;
	bool testPrenume;
	~Bank();

	//method to add accounts in the "bank"
	void adaugareCont();

	//method to see the bank accounts
	void vizualizareConturi();

	//method to modify a bank account
	void modificareCont();
};

