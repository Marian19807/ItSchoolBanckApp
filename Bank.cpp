#include "Bank.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>
std::string Bank::createIban()
{
	//we are creating an unique iban

	srand(time(0));
	std::string iban1 = { "RO" };
	for (int m = 0; m < 2; m++)
	{
		iban1 = iban1 + std::to_string(rand() % 10);
	}
	iban1 = iban1 + " BCRL ";
	for (int m = 0; m < 4; m++)
	{
		iban1 = iban1 + std::to_string(rand() % 10);
	}
	iban1 = iban1 + " ";
	for (int m = 0; m < 4; m++)
	{
		iban1 = iban1 + std::to_string(rand() % 10);
	}
	iban1 = iban1 + " ";
	for (int m = 0; m < 4; m++)
	{
		iban1 = iban1 + std::to_string(rand() % 10);
	}



	return iban1;

	
}

Bank::Bank()
{
	 schimbare = false;
	 testNume=false;
	 testPrenume=false;
}

Bank::~Bank()
{
	m_ConturiBancare.clear();
	
}

void Bank::adaugareCont()
{
	//we are reading data from a csv.file
	std::ifstream file("Baza_Date.csv");
	if (!file.is_open()) std::cout << "Error!\n";

	std::string nume_csv;
	std::string prenume_csv;
	std::string iban1;
	std::string iban2;
	std::string iban3;
	std::string iban4;
	std::string iban5;
	std::string iban_csv;

	while (file.good())
	{
		iban_csv.clear();
		nume_csv.clear();
		prenume_csv.clear();
		iban1.clear();
		iban2.clear();
		iban3.clear();
		iban4.clear();
		iban5.clear();

		std::getline(file, nume_csv, ' ');
		std::getline(file, prenume_csv, ' ');
		std::getline(file, iban1, ' ');
		std::getline(file, iban2, ' ');
		std::getline(file, iban3, ' ');
		std::getline(file, iban4, ' ');
		std::getline(file, iban5, '\n');
		if (nume_csv == "")
		{
			break;
		}
		else
		{
			iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
			ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
			m_ConturiBancare.push_back(Cont);
		}
	}
	file.close();

	system("CLS");
	std::cout << "Type in the user's last name: " << std::endl;
	testNume = true;
	std::string nume;
	do
	{
		std::cin >> nume;
		std::string numeMagazie;

		//we are making sure that the operator types only alphabetical caracters and we use a do while loop to repeat the proces till the operattor will type in only alphabetical carracters
		for (int i = 0; i < nume.size(); i++)
		{
			if (nume[i] >= 48 && nume[i] <= 57 || nume[i] >= 65 && nume[i] <= 90 || nume[i] >= 97 && nume[i] <= 122 || nume[i] == 32 || nume[i] == 45 || nume[i] == 46)
			{
				numeMagazie = numeMagazie + nume[i];
				testNume = false;
				continue;
			}
			else
				std::cout << "Wrong Key! Please type in the user's last name again \n";
			i = nume.size()-1;
			testNume = true;
		}
		nume = numeMagazie;
		
	} while (testNume);

	std::cout << "Type in the user's first name: " << std::endl;
	testPrenume = true;
	std::string prenume;

	do
	{
		std::cin >> prenume;
		std::string prenumeMagazie;

		//we are making sure that the operator types only alphabetical caracters and we use a do while loop to repeat the proces till the operattor will type in only alphabetical carracters
		for (int i = 0; i < prenume.size(); i++)
		{
			if (prenume[i] >= 48 && prenume[i] <= 57 || prenume[i] >= 65 && prenume[i] <= 90 || prenume[i] >= 97 && prenume[i] <= 122 || prenume[i] == 32 || prenume[i] == 45 || prenume[i] == 46)
			{
				prenumeMagazie = prenumeMagazie + prenume[i];
				testPrenume = false;
				continue;
			}
			else
				std::cout << "Wrong Key! Please type in the user's first name again \n";
			i = prenume.size()-1;
			testPrenume = true;
		}
		prenume = prenumeMagazie;
	} while (testPrenume);

	std::string iban = createIban();
	
	ContBancar* Cont = new ContBancar(nume, prenume, iban);
	m_ConturiBancare.push_back(Cont);
	
	//we are writing in a csv.file the last name, first name and the iban
	std::ofstream ObjectFile("Baza_Date.csv");
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		ObjectFile << m_ConturiBancare[i]->getNume() << " " << m_ConturiBancare[i]->getPrenume() << " " << m_ConturiBancare[i]->getIban() << std::endl;
	}
	ObjectFile.close();

	//we are reading the bank accounts from csv.file
	while (file.good())
	{
		iban_csv.clear();
		nume_csv.clear();
		prenume_csv.clear();
		iban1.clear();
		iban2.clear();
		iban3.clear();
		iban4.clear();
		iban5.clear();

		std::getline(file, nume_csv, ' ');
		std::getline(file, prenume_csv, ' ');
		std::getline(file, iban1, ' ');
		std::getline(file, iban2, ' ');
		std::getline(file, iban3, ' ');
		std::getline(file, iban4, ' ');
		std::getline(file, iban5, '\n');
		if (nume_csv == "")
		{
			break;
		}
		else
		{
			iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
			ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
			m_ConturiBancare.push_back(Cont);
		}
	}
	file.close();
	//we clear the object 
	m_ConturiBancare.clear();

	std::cout << "1-> Add another account\n";
	std::cout << "2-> Return to Menu\n";
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
	//we are reading data from a csv.file
	std::ifstream file("Baza_Date.csv");
	if (!file.is_open()) std::cout << "Error!\n";
	
	std::string nume_csv;
	std::string prenume_csv;
	std::string iban1;
	std::string iban2;
	std::string iban3;
	std::string iban4;
	std::string iban5;
	std::string iban_csv;

	while (file.good())
	{
		iban_csv.clear();
		nume_csv.clear();
		prenume_csv.clear();
		iban1.clear();
		iban2.clear();
		iban3.clear();
		iban4.clear();
		iban5.clear();
		
		std::getline(file, nume_csv, ' ');
		std::getline(file, prenume_csv, ' ');
		std::getline(file, iban1, ' ');
		std::getline(file, iban2, ' ');
		std::getline(file, iban3, ' ');
		std::getline(file, iban4, ' ');
		std::getline(file, iban5, '\n');
		if (nume_csv == "")
		{ 
			break; 
		}
		else 
		{
			iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
			ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
			m_ConturiBancare.push_back(Cont);
		}
	}
	file.close();

	    //we are writing on the console the bank accounts
		std::cout << "The number of bank accounts is: " << m_ConturiBancare.size() << std::endl;
		for (int i = 0; i < m_ConturiBancare.size(); i++)
		{
			std::cout << "The account no. " << i + 1 << " " << m_ConturiBancare[i]->getNume() << " iban: " << m_ConturiBancare[i]->getIban() << std::endl;
		}
	
		//we are deleting the object of bank accounts before calling other methods
		m_ConturiBancare.clear();
	std::cout << "1-> Add another account\n";
	std::cout << "2-> Return to Menu\n";
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
	//we are reading data from a csv.file
	std::ifstream file("Baza_Date.csv");
	if (!file.is_open()) std::cout << "Error!\n";

	std::string nume_csv;
	std::string prenume_csv;
	std::string iban1;
	std::string iban2;
	std::string iban3;
	std::string iban4;
	std::string iban5;
	std::string iban_csv;

	while (file.good())
	{
		iban_csv.clear();
		nume_csv.clear();
		prenume_csv.clear();
		iban1.clear();
		iban2.clear();
		iban3.clear();
		iban4.clear();
		iban5.clear();

		std::getline(file, nume_csv, ' ');
		std::getline(file, prenume_csv, ' ');
		std::getline(file, iban1, ' ');
		std::getline(file, iban2, ' ');
		std::getline(file, iban3, ' ');
		std::getline(file, iban4, ' ');
		std::getline(file, iban5, '\n');
		if (nume_csv == "")
		{
			break;
		}
		else
		{
			iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
			ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
			m_ConturiBancare.push_back(Cont);
		}
	}
	file.close();
	system("CLS");
	//We ask the operator what bank account does he want to modify
	std::cout << "Type in the account`s first and last name\n";
	std::cout << "Type in the last name\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Type in the first name\n";
	std::string prenume;
	std::cin >> prenume;
	//we ar searching for the bank account
	ContBancar* temp = nullptr;
	
	std::vector<ContBancar*>::iterator it;
	for (it = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->getNume() && prenume == (*it)->getPrenume())
		{
			temp = *it;
			break;
		}
	}
	if (temp == nullptr)//If we do not find the account:
	{
		std::cout << "The account was not found\n";
		std::cout << "1-> Return to menu\n";
		std::cout << "2-> Add an account\n";
		std::cout << "3-> Search for another account\n";

		std::ofstream ObjectFile("Baza_Date.csv");
		for (int i = 0; i < m_ConturiBancare.size(); i++)
		{
			ObjectFile << m_ConturiBancare[i]->getNume() << " " << m_ConturiBancare[i]->getPrenume() << " " << m_ConturiBancare[i]->getIban() << std::endl;
		}
		ObjectFile.close();
		while (file.good())
		{
			iban_csv.clear();
			nume_csv.clear();
			prenume_csv.clear();
			iban1.clear();
			iban2.clear();
			iban3.clear();
			iban4.clear();
			iban5.clear();

			std::getline(file, nume_csv, ' ');
			std::getline(file, prenume_csv, ' ');
			std::getline(file, iban1, ' ');
			std::getline(file, iban2, ' ');
			std::getline(file, iban3, ' ');
			std::getline(file, iban4, ' ');
			std::getline(file, iban5, '\n');
			if (nume_csv == "")
			{
				break;
			}
			else
			{
				iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
				ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
				m_ConturiBancare.push_back(Cont);
			}
		}
		file.close();
		m_ConturiBancare.clear();

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

		std::cout << "What changes do you want to make?\n";
		std::cout << "1-> Change the last name\n";
		std::cout << "2-> Change the first name\n";
		std::cout << "3-> Delete account\n";
		std::cout << "4-> Return to menu\n";
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
				std::cout << "Type in the new last name\n";
				std::cin >> firstName;
				(*it)->setNume(firstName);
				std::cout << "Do you want to make another change?\n";
				std::cout << "1-> Yes\n";
				std::cout << "0-> Return to menu\n";
				std::cin >> schimbare;

				{std::ofstream ObjectFile("Baza_Date.csv");
				for (int i = 0; i < m_ConturiBancare.size(); i++)
				{
					ObjectFile << m_ConturiBancare[i]->getNume() << " " << m_ConturiBancare[i]->getPrenume() << " " << m_ConturiBancare[i]->getIban() << std::endl;
				}
				ObjectFile.close();
				while (file.good())
				{
					iban_csv.clear();
					nume_csv.clear();
					prenume_csv.clear();
					iban1.clear();
					iban2.clear();
					iban3.clear();
					iban4.clear();
					iban5.clear();

					std::getline(file, nume_csv, ' ');
					std::getline(file, prenume_csv, ' ');
					std::getline(file, iban1, ' ');
					std::getline(file, iban2, ' ');
					std::getline(file, iban3, ' ');
					std::getline(file, iban4, ' ');
					std::getline(file, iban5, '\n');
					if (nume_csv == "")
					{
						break;
					}
					else
					{
						iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
						ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
						m_ConturiBancare.push_back(Cont);
					}
				}
				file.close();
				m_ConturiBancare.clear();
				}


				if (schimbare)
				{
					
					modificareCont();
					break;
				}
				
				break;
			case'2':
				std::cout << "Type in the new first name\n";
				std::cin >> lastName;
				(*it)->setPrenume(lastName); 
				std::cout << "Do you want to make another change?\n";
				std::cout << "1-> Yes\n";
				std::cout << "0-> Return to menu\n";
				std::cin >> schimbare;
				{
					std::ofstream ObjectFile("Baza_Date.csv");
					for (int i = 0; i < m_ConturiBancare.size(); i++)
					{
						ObjectFile << m_ConturiBancare[i]->getNume() << " " << m_ConturiBancare[i]->getPrenume() << " " << m_ConturiBancare[i]->getIban() << std::endl;
					}
					ObjectFile.close();
					while (file.good())
					{
						iban_csv.clear();
						nume_csv.clear();
						prenume_csv.clear();
						iban1.clear();
						iban2.clear();
						iban3.clear();
						iban4.clear();
						iban5.clear();

						std::getline(file, nume_csv, ' ');
						std::getline(file, prenume_csv, ' ');
						std::getline(file, iban1, ' ');
						std::getline(file, iban2, ' ');
						std::getline(file, iban3, ' ');
						std::getline(file, iban4, ' ');
						std::getline(file, iban5, '\n');
						if (nume_csv == "")
						{
							break;
						}
						else
						{
							iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
							ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
							m_ConturiBancare.push_back(Cont);
						}
					}
					file.close();
					m_ConturiBancare.clear();
				}
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
				std::cout << "Delete completed! Do you want to make another change?\n";
				std::cout << "1-> Yes\n";
				std::cout << "0-> Return to menu\n";
				std::cin >> schimbare;
				std::ofstream ObjectFile("Baza_Date.csv");
				for (int i = 0; i < m_ConturiBancare.size(); i++)
				{
					ObjectFile << m_ConturiBancare[i]->getNume() << " " << m_ConturiBancare[i]->getPrenume() << " " << m_ConturiBancare[i]->getIban() << std::endl;
				}
				ObjectFile.close();
				while (file.good())
				{
					iban_csv.clear();
					nume_csv.clear();
					prenume_csv.clear();
					iban1.clear();
					iban2.clear();
					iban3.clear();
					iban4.clear();
					iban5.clear();

					std::getline(file, nume_csv, ' ');
					std::getline(file, prenume_csv, ' ');
					std::getline(file, iban1, ' ');
					std::getline(file, iban2, ' ');
					std::getline(file, iban3, ' ');
					std::getline(file, iban4, ' ');
					std::getline(file, iban5, '\n');
					if (nume_csv == "")
					{
						break;
					}
					else
					{
						iban_csv = iban1 + " " + iban2 + " " + iban3 + " " + iban4 + " " + iban5;
						ContBancar* Cont = new ContBancar(nume_csv, prenume_csv, iban_csv);
						m_ConturiBancare.push_back(Cont);
					}
				}
				file.close();
				m_ConturiBancare.clear();
				if (schimbare)
				{
					modificareCont();
					
					break;
				}
				break;
			}
		} while (schimbare);
	}
}
