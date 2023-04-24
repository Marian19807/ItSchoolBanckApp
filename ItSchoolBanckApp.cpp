

#include <iostream>
#include <fstream>
#include"Bank.h"

int main()
{
    
    std::string parolaStocata = "password123";
    std::string usserIdStocat = "Marian";
   
    std::string usserId;
    std::string parola;
    std::cout << "Please type in the Id and the password: \n";
    
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Please type in the Id: \n";
        std::cin >> usserId;
        std::cout << "Please type in the password: \n";
        std::cin >> parola;
        if (usserIdStocat==usserId&&parolaStocata==parola)
        {
            {
                //we are creating a bank
                Bank* itSchoolBank = new Bank();
                bool isRunning = true;
                std::ofstream test("BazaDeDate.csv");
                test << "Test\n";
                test << "1\n";
                test << "2\n";
                test.close();
                std::ifstream testCitire("BazaDeDate.csv");
                if (!testCitire.is_open())
                {
                    std::cout << "Fisierul nu poate fi deschis";

                }
                if (testCitire.good())
                {
                    std::string line;
                    while (std::getline(testCitire, line))

                    {
                        std::cout << line << std::endl;

                    }

                }

                testCitire.close();


                do
                {
                    system("CLS");
                    std::cout << "Menu \n";
                    std::cout << "1-> Add Account\n";
                    std::cout << "2-> View Accounts\n";
                    std::cout << "3-> Editing Accounts\n";
                    std::cout << "9-> Exit\n";
                    std::cout << "Type in your option: \n";
                    char optiune;
                    std::cin >> optiune;
                    switch (optiune)
                    {
                    case'1':
                        system("CLS");
                        itSchoolBank->adaugareCont();
                        break;
                    case'2':
                        system("CLS");
                        itSchoolBank->vizualizareConturi();

                        break;
                    case'3':
                        system("CLS");
                        itSchoolBank->modificareCont();

                        break;
                    case'9':
                        std::cout << "Thank you!\n";
                        isRunning = false;
                        break;
                    default:
                        system("CLS");
                        std::cout << "Invalid Option\;";
                        isRunning = false;
                        break;
                    }
                } while (isRunning);

                delete itSchoolBank;
            }
            i = 3;
        }
        else
        {
            
            if(i==0)
            {
                system("CLS");
                std::cout << "Sorry! The Id and the password do not match. You have: " << 2 - i << " more attempts. \n";
                 
            
            }
            if (i == 1)
            {
                system("CLS");
                std::cout << "Sorry! The Id and the password do not match. You have: " << 2 - i << " attempt left. \n";
              

            }
            if (i == 2)
            {
                system("CLS");
                std::cout << "You have no more attempts! Goodbye!\n";
              
            }
        }
    }
}