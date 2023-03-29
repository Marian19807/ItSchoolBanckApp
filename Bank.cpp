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
	testNume = true;
	std::string nume;
	do
	{
		std::cin >> nume;
		std::string numeMagazie;


		for (int i = 0; i < nume.size(); i++)
		{
			if (nume[i] >= 48 && nume[i] <= 57 || nume[i] >= 65 && nume[i] <= 90 || nume[i] >= 97 && nume[i] <= 122 || nume[i] == 32 || nume[i] == 45 || nume[i] == 46)
			{
				numeMagazie = numeMagazie + nume[i];
				testNume = false;
				continue;
			}
			else
				std::cout << "Tasta introdusa nu este valida!Va rugam introduceti din nou numele \n";
			i = nume.size()-1;
			testNume = true;
		}
		nume = numeMagazie;
		
	} while (testNume);

	std::cout << "Introduceti prenumele utilizatorului: " << std::endl;
	testPrenume = true;
	std::string prenume;

	do
	{
		std::cin >> prenume;
		std::string prenumeMagazie;


		for (int i = 0; i < prenume.size(); i++)
		{
			if (prenume[i] >= 48 && prenume[i] <= 57 || prenume[i] >= 65 && prenume[i] <= 90 || prenume[i] >= 97 && prenume[i] <= 122 || prenume[i] == 32 || prenume[i] == 45 || prenume[i] == 46)
			{
				prenumeMagazie = prenumeMagazie + prenume[i];
				testPrenume = false;
				continue;
			}
			else
				std::cout << "Tasta introdusa nu este valida!Va rugam introduceti din nou prenumele \n";
			i = prenume.size()-1;
			testPrenume = true;
		}
		prenume = prenumeMagazie;
	} while (testPrenume);

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
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->getNume()<< std::endl;
	}
	std::cout << "1-> pentru crearea unui nou cont\n";
	std::cout << "2-> pentru meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case'1':
		adaugareCont();
		break;
	default:
		break;

	}
}

void Bank::modificareCont()
{
	system("CLS");
	//system("pause");
	//intrebati operatorul care cont doreste sa-l modifice
	std::cout << "Introduceti numele si prenumele contului\n";
	std::cout << "Introduceti numele de familie\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele\n";
	std::string prenume;
	std::cin >> prenume;
	//cautati contul
	ContBancar* temp =nullptr;
	//int foundIndex = 0;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		if (nume == m_ConturiBancare[i]->getNume() && prenume == m_ConturiBancare[i]->getPrenume());
		{
			temp = m_ConturiBancare[i];
		//	foundIndex = i;
			break;

		}


	}
	std::vector<ContBancar*>::iterator it;
	for (it=m_ConturiBancare.begin(); it != m_ConturiBancare.end();it++)
	{
		if (nume==(*it)->getNume()&& prenume ==(*it)->getPrenume())
		{
			temp = *it;
				break;
		}
	}
	if(temp==nullptr)//in cazul in care nu gasim contul
	{
		std::cout << "Contul nu a fost gasit\n";
		std::cout << "1-> Intoarcere la meniul principal\n";
		std::cout << "2-> Creati un cont\n";
		std::cout << "3-> Cautati un alt cont\n";

		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case'1':
			std::cout << "Going back\n";
			break;
		case'2':
			adaugareCont();
			break;
		case'3':
			modificareCont();
			break;

		default:
			break;
		}


	}
	else

	{
		
		std::cout << "Ce modificari vreti sa faceti?\n";
		std::cout << "1-> Pentru modificare nume\n";
		std::cout << "2-> Pentru modificare prenume\n";
		std::cout << "3-> Pentru stergere cont\n";
		std::cout << "4-> Pentru a reveni la meniul principal\n";
		char optiune1;
		std::cin >> optiune1;
		std::string firstName;
		std::string lastName;

		schimbare = true;

		do
		{
			
				switch (optiune1)
				{

				case'1':
					std::cout << "Introduceti noul nume\n";
					std::cin >> firstName;
					(*it)->setNume(firstName);
					std::cout << "Doriti sa faceti o noua schimbare?\n";
					std::cout << "1-> Da\n";
					std::cout << "0-> Reveniti la meniul pricipal\n";
					std::cin >> schimbare;
					if (schimbare)
					{
						modificareCont();
						break;
					}

					break;
				case'2':
					std::cout << "Introduceti noul prenume\n";
					std::cin >> lastName;
					(*it)->setPrenume(lastName);
					std::cout << "Doriti sa faceti o noua schimbare?\n";
					std::cout << "1-> Da\n";
					std::cout << "0-> Reveniti la meniul pricipal\n";
					std::cin >> schimbare;
					if (schimbare)
					{
						modificareCont();
						break;
					}
					break;
				case'4':
					schimbare = false;
					break;
				default:
					m_ConturiBancare.erase(it);
					std::cout << "Contul a fost sters! Doriti sa faceti o noua schimbare?\n";
					std::cout << "1-> Da\n";
					std::cout << "0-> Reveniti la meniul pricipal\n";
					std::cin >> schimbare;
					if (schimbare)
					{
						modificareCont();
						break;
					}
					//system("pause");
					break;
				}
			
		} while (schimbare);
		
		
		
		//modif nume
		//modif prenume
		//stergeti contul gasit
	
	
	}
	//std::cout << "Numele contului cautat : " << temp->getNume();
	
				//-daca exista intrebam ce modificari facem
	            //-daca nu exista spunem ca nu ex si dam urm optiuni
					//-return to main
					//-creati un cont
					//-cautati alt cont
}
