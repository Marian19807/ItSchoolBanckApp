

#include <iostream>
#include"Bank.h"
int main()
{
    std::string parolaStocata = "password123";
    std::string usserIdStocat = "Marian";
   
    std::string usserId;
    std::string parola;
    std::cout << "Va rugam introduceti id-ul si parola: \n";
    
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Va rugam introduceti id-ul: \n";
        std::cin >> usserId;
        std::cout << "Va rugam introduceti parola: \n";
        std::cin >> parola;
        if (usserIdStocat==usserId&&parolaStocata==parola)
        {
            {
                //instantam o banca
                Bank* itSchoolBank = new Bank();
                bool isRunning = true;
                /*std::ofstream test("BazaDeDate.csv");
                test << "Test\n";
                test << "1\n";
                test << "2\n";*/
                //test.close();
               /* std::ifstream testCitire("BazzaDeDate.csv");
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

                testCitire.close();*/


                do
                {
                    system("CLS");
                    std::cout << "Meniu Principal\n";
                    std::cout << "1-> Adaugare Cont\n";
                    std::cout << "2-> Vizualizare Conturi\n";
                    std::cout << "3-> Modificare Conturi\n";
                    std::cout << "9-> Exit\n";
                    std::cout << "Introduceti optiunea: \n";
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
                        std::cout << "Multumim\n";
                        isRunning = false;
                        break;
                    default:
                        system("CLS");
                        std::cout << "Optiunea nu este valida\;";
                        isRunning = false;
                        break;
                    }
                } while (isRunning);





                //chemam pt test adaugare cont
               /* itSchoolBank->adaugareCont();
                itSchoolBank->vizualizareConturi();*/
                delete itSchoolBank;
            }
            i = 3;
        }
        else
        {
            //switch (i)
            //{case'0':
            //    std::cout << "Ne pare rau, id-ul si parola introduse nu se potrivesc. Mai aveti: " << 2 - i << " incercari; \n";
            //    break;
            //case'1':
            //    std::cout << "Ne pare rau, id-ul si parola introduse nu se potrivesc. Mai aveti: " << 2 - i << " incercare; \n";
            //    break;
            //default:
            //   // std::cout << "Nu mai aveti nicio-o incercare! La revedere!\n";
            //   // system("pause");
            //    break;
            //}
            if(i==0)
            {
                system("CLS");
                std::cout << "Ne pare rau, id-ul si parola introduse nu se potrivesc. Mai aveti: " << 2 - i << " incercari; \n";
                 
            
            }
            if (i == 1)
            {
                system("CLS");
                std::cout << "Ne pare rau, id-ul si parola introduse nu se potrivesc. Mai aveti: " << 2 - i << " incercare; \n";
              

            }
            if (i == 2)
            {
                system("CLS");
                std::cout << "Nu mai aveti nicio-o incercare! La revedere!\n";
              
            }
        }
    }
}