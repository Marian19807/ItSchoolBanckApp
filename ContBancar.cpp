#include "ContBancar.h"


ContBancar::ContBancar(std::string numeOb, std::string prenumeOb, std::string iban)
{
	nume = numeOb;
	prenume = prenumeOb;
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

ContBancar::~ContBancar()
{
}
