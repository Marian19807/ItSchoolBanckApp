#pragma once
#include<string>
enum class TIP_CONT
{
	CONT_RON, CONT_EURO, CONT_DOLAR, NECUNOSCUT

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
	inline std::string getNume() { return nume; }
	inline std::string getPrenume() { return prenume; }
	inline int getSold() { return sold; }
	inline std::string getIban() {   return IBAN;}
	inline void setSoldValue(int value) { sold = value; }
	void setNume(std::string numeClient);
	void setPrenume(std::string prenumeClient);
	

	~ContBancar();
	
};

