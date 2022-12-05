#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include "Income.h"



#include "MainBudgetFile.h"

using namespace std;

class IncomeFile : public MainBudgetFile
{
    int lastIncomeId;

    void readLastIncomeId();

public:
    IncomeFile()
        {
            readLastIncomeId();
        }
    int getLastIncomeId();
    void setLastIncomeId(int lastId);
    void addNewIncomeIntoFile(Income income);



};



#endif
