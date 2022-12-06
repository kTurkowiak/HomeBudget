#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <string>
#include <vector>

#include "Income.h"
#include "Expense.h"
#include "ExpenseFile.h"
#include "IncomeFile.h"
#include "SupportMethod.h"
#include "DateManager.h"


using namespace std;

class BudgetManager
{
    const int CURRENT_LOGEDIN_USER;
    //vector <Expense> expenses;
    vector <Income> incomes;
    DateManager dateManager;
    IncomeFile incomeFile;
    //ExpenseFile expenseFile;

    Income getNewIncomeData(int lastId);
    float checkDataCorrectFloat (string number);
    int checkDataCorrectInt (string dataValid);





public:
    BudgetManager (int currentLogInUser)
    : CURRENT_LOGEDIN_USER (currentLogInUser)
    {
        //expenses = expenseFile.
        incomes = incomeFile.loadIncomeCurrentLogedUser(CURRENT_LOGEDIN_USER);
    }

    void addNewIncome();
    void showAllIncome();                       //do pozniejszego usuniecia
};



#endif
