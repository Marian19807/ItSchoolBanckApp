#include "ContBancar.h"


ContBancar::ContBancar(std::string nume, std::string prenume, std::string iban)
{
	this->nume = nume;
	this->prenume = prenume;
	this->
	IBAN = iban;
	sold = 0;
	eTipCont = TIP_CONT::CONT_RON;
}


void ContBancar::setNume(std::string numeStudent)
{
	nume=numeStudent;
}

void ContBancar::setPrenume(std::string prenumeStudent)
{
	prenume = prenumeStudent;
}
std::string ContBancar::getIban()
{
	std::string sIban[6]{ "RO","ITBK" };

	for (int i = 5; i > 2; i--)
	{
		(i==5)? srand(time(NULL)): srand(std::stoi)




	}





}
ContBancar::~ContBancar()
{
}
