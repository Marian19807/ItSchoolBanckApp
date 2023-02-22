#pragma once
#include<string>
enum class TIP_CONT
{
	CONT_RON , CONT_EURO

};
class ContBancar
{
private:
	std::string nume;
	std::string prenume;
	int sold;
	TIP_CONT eTipCont;
	std::string IBAN;
public:
	ContBancar(std::string nume, std::string prenume, std::string iban);
	~ContBancar();

};

