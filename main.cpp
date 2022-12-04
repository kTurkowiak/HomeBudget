#include <iostream>


#include "HomeBudget.h"

using namespace std;

int main()
{
    HomeBudget homeBudget;
    char menuChoose;
    while (true)
    {

        if (!homeBudget.didUserLogIn())
        {
            menuChoose = homeBudget.userMenuChoose();
            switch (menuChoose)
            {
            case '1':
                homeBudget.userRegistration();
                break;
            case '2':
                homeBudget.userLogIn();
                break;
            case '9':
                exit(0);
            default:
                cout << endl << "Nie ma takiej opcji, wybierz ponownie." << endl << endl;
                system("pause");
                break;
            }
        }

        else
        {
            menuChoose = homeBudget.mainMenuChoose();
            switch (menuChoose)
            {
            case '1':
                homeBudget.addNewIncome();
                break;
            case '2':
                //homeBudget.addNewExpense();
                break;
            case '3':
                //homeBudget.showBalanceForCurrentMonth();
                break;
            case '4':
                //homeBudget.showBalanceForPreviousMonth();
                break;
            case '5':
                //homeBudget.showBalanceForChoosenMonth();
                break;
            case '6':
                homeBudget.changePassword();
                break;
            case '7':
                homeBudget.userLogOut();
                break;
            default:
                cout << endl << "Nie ma takiej opcji, wybierz ponownie." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
