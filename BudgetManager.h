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


using namespace std;

class BudgetManager
{
    const int CURRENT_LOGEDIN_USER;
    //vector <Expense> expenses;
    vector <Income> incomes;

    IncomeFile incomeFile;
    //ExpenseFile expenseFile;

    Income getNewIncomeData(int lastId);
    float checkDataCorrectFloat (string number);


public:
    BudgetManager (int currentLogInUser)
    : CURRENT_LOGEDIN_USER (currentLogInUser)
    {
        //expenses = expenseFile.
        //incomes = incomeFile.
    }

    void addNewIncome();
};



#endif
