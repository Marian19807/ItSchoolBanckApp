#include "Bank.h"

std::string Bank::createIban()
{
	//trebuie sa existe ca sa fie un iban unic
	std::string iban = "123";

	return iban;
}

Bank::Bank()
{
}

Bank::~Bank()
{
	m_ConturiBancare.clear();
}

void Bank::adaugareCont()
{
	system("CLS");
	std::cout << "Introduceti numele utilizatorului: " << std::endl;
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele utilizatorului: " << std::endl;
	std::string prenume;
	std::cin >> prenume;
	std::string iban = createIban();
	ContBancar* Cont = new ContBancar(nume, prenume, iban);
	m_ConturiBancare.push_back(Cont);
	std::cout << "1-> pentru crearea unui nou cont\n";
	std::cout << "2-> pentru meniul principal\n";
	char optiune;
	std::cin >>optiune;
	switch (optiune)
	{
	case'1':
		adaugareCont();
		break;
	default:
		break;

	}

}
void Bank::vizualizareConturi()
{
	std::cout << "Numarul de conturi din banca este: " << m_ConturiBancare.size() << std::endl;
	for(int i=0;i<m_ConturiBancare.size();i++)
	{
		std::cout << "Contul " << i+1 << " " << m_ConturiBancare[i]->getNume()
			;
	}
}