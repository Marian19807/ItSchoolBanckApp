#pragma once
#include"ContBancar.h"
#include<vector>
#include<iostream>
class Bank
{
	std::vector<ContBancar*> m_ConturiBancare;
	std::string createIban();
public:
	Bank();
	bool schimbare;
	bool testNume;
	bool testPrenume;
	~Bank();
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();
};

