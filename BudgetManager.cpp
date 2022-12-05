#include "BudgetManager.h"

void BudgetManager::addNewIncome()
{
    Income income;
    int lastId = incomeFile.getLastIncomeId();
    income = getNewIncomeData(lastId);
    incomeFile.addNewIncomeIntoFile(income);
    incomeFile.setLastIncomeId(lastId+1);
}

Income BudgetManager::getNewIncomeData(int lastId)
{
    Income income;
    income.setUserId(CURRENT_LOGEDIN_USER);
    income.setCostId(lastId+1);
    float temporaryValue;
    string temporaryString;
    bool dataCorrect = 1;

    cout << "Podaj date: ";
    //funkcja sprawdzajaca czy data dzisiejsza
    //funkcja sprawdzajaca poprawnosc daty
    income.setCostDate(20221205);
    cout << "Podaj nazwe przychodu: ";
    income.setCostItem(SupportMethod::loadLine());
    do
    {
        dataCorrect = 1;
        cout << "Podaj wielkosc przychodu: " ;
        temporaryString = (SupportMethod::loadLine());
        temporaryValue = BudgetManager::checkDataCorrectFloat(temporaryString);
        if (temporaryValue == -1)
        {
            dataCorrect=0;
        }
    } while (dataCorrect != 1);
    income.setCostAmount(temporaryValue);

    return income;
}


float BudgetManager::checkDataCorrectFloat (string number)
{
    int stringLength =  number.length();
    string temporaryOne, temporaryTwo, total;
    char temporaryCharacter;
    int temporaryCharacterInt, temporaryTwoInt;
    bool afterSpecialMark = 0;
    for (int i = 0; i< stringLength; i++)
    {
        temporaryCharacter = number[i];
        temporaryCharacterInt = (int) temporaryCharacter;
        if ((temporaryCharacterInt>=48) && (temporaryCharacterInt <=57) && (afterSpecialMark == 0))
        {
            temporaryOne = temporaryOne + temporaryCharacter;
        }
        else if ((temporaryCharacterInt == 44) ||(temporaryCharacterInt == 46))
        {
            afterSpecialMark = 1;
        }
        else if ((temporaryCharacterInt>=48) && (temporaryCharacterInt <=57) && (afterSpecialMark == 1))
        {
            temporaryTwo = temporaryTwo + temporaryCharacter;
        }
        else
        {
            return -1;
        }
    }
    temporaryTwoInt = SupportMethod::convertStringToInt(temporaryTwo);
    if (temporaryTwoInt >=100)
    {
        return -1;
    }
    total = temporaryOne + '.' + temporaryTwo;
    return SupportMethod::convertStringToFloat(total);
}
