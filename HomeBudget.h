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
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    HomeBudget(string userFileName, string incomeFileName, string expenseFileName)
    :userManager(userFileName),INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName)
    {
     budgetManager = NULL;
    };
    char userMenuChoose();
    char mainMenuChoose();
    void userRegistration();
    void userLogIn();
    bool didUserLogIn();
    void userLogOut();
    void addNewIncome();
    void addNewExpense();
    void changePassword();
    void showBalanceForCurrentMonth();
    void showBalanceForPreviousMonth();
    void showBalanceForChoosenPeriod();


    ~HomeBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    };
};



#endif

