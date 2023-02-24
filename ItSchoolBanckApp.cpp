

#include <iostream>
#include"Bank.h"
int main()
{
    //instantam o banca
    Bank* itSchoolBank = new Bank();
    bool isRunning = true;
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
        case'9':
            std::cout << "Multumim\n";
            isRunning = false;
            break;
        default:
            system("CLS");
            std::cout << "Optiunea nu este valida\;";
            break;
        }
    } while (isRunning);
    

    


    //chemam pt test adaugare cont
   /* itSchoolBank->adaugareCont();
    itSchoolBank->vizualizareConturi();*/
    delete itSchoolBank;
}

