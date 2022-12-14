#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

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
    vector <Expense> expenses;
    vector <Income> incomes;
    DateManager dateManager;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    Income getNewIncomeData(int lastIncomeId);
    Expense getNewExpenceData(int lastExpeseId);
    float checkDataCorrectFloat (string number);
    int checkDateCorrectInt (string dataValid);
    void sortingIncomeAndExpense();



public:
    BudgetManager (int currentLogInUser, string incomeFileName, string expenseFileName)
    :CURRENT_LOGEDIN_USER (currentLogInUser), incomeFile(incomeFileName), expenseFile(expenseFileName)
    {
        incomes = incomeFile.loadIncomeCurrentLogedUser(CURRENT_LOGEDIN_USER);
        expenses = expenseFile.loadExpenseCurrentLogedUser (CURRENT_LOGEDIN_USER);


    };
    void addNewIncome();
    void addNewExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForPreviousMonth();
    void showBalanceForChoosenPeriod();

};



#endif
