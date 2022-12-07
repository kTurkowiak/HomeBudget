#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include "Expense.h"
#include "Markup.h"
#include "SupportMethod.h"

using namespace std;

class ExpenseFile
{
    const string FILE_NAME;
    int lastExpenseId;

    void readLastExpenseId();

public:
    ExpenseFile(string expenseFileName)
    :FILE_NAME(expenseFileName)
    {
        readLastExpenseId();
    };
    int getLastExpenseId();
    void setLastExpenseId(int lastId);
    void addNewExpenseIntoFile(Expense expense);
    vector <Expense> loadExpenseCurrentLogedUser(int currentLogInUser);
};



#endif
