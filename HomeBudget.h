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
<<<<<<< HEAD


public:
    HomeBudget()
    {

=======
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;



public:
    HomeBudget(string userFileName, string incomeFileName, string expenseFileName)
    :userManager(userFileName),INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName)
    {
     budgetManager = NULL;
>>>>>>> feature_creating-cost-class,inheritance-it-to-Income-and-Expense-classes
    }
    char userMenuChoose();
    char mainMenuChoose();
    void userRegistration();
    void userLogIn();
    bool didUserLogIn();
    void userLogOut();
    void addNewIncome();
<<<<<<< HEAD
    void changePassword();
    void showAllIncome(); //do pozniejszego usuniecia

=======
    void addNewExpense();
    void changePassword();
    void showAllIncome(); //do pozniejszego usuniecia
    void showAllExpense();
>>>>>>> feature_creating-cost-class,inheritance-it-to-Income-and-Expense-classes

    ~HomeBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    }


};



#endif

