#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <cstdlib>
#include <iostream>

#include "SupportMethod.h"
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;
    BudgetManager *budgetManager;


public:
    HomeBudget()
    {

    }
    char userMenuChoose();
    char mainMenuChoose();
    void userRegistration();
    void userLogIn();
    bool didUserLogIn();
    void userLogOut();
    void addNewIncome();
    void changePassword();
    void showAllIncome(); //do pozniejszego usuniecia


    ~HomeBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    }


};



#endif

