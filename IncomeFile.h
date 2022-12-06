#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include "Income.h"
#include "Markup.h"
#include "SupportMethod.h"


using namespace std;

class IncomeFile
{
    const string FILE_NAME;
    int lastIncomeId;

    void readLastIncomeId();

public:
    IncomeFile(string incomeFileName)
    : FILE_NAME(incomeFileName)
        {
            readLastIncomeId();
        }
    int getLastIncomeId();
    void setLastIncomeId(int lastId);
    void addNewIncomeIntoFile(Income income);
    vector <Income> loadIncomeCurrentLogedUser(int currentLogInUser);




};



#endif
