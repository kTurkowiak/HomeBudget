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
    char choose;
    income.setUserId(CURRENT_LOGEDIN_USER);
    income.setCostId(lastId+1);
    float temporaryValue;
    string temporaryString;
    int temporaryInt;
    bool dataCorrect = 0;

    do{
        cout << "Jaka date chcesz ustawic?" << endl;
        cout << "1. Data dzisiejsza: " << dateManager.getTotalTodayDateAsString() << "?"<< endl;
        cout << "2. Data wlasna" << endl;
        choose = SupportMethod::loadChar();
        switch (choose)
        {
            case '1':
            {
                temporaryInt = dateManager.getFullTodayDateAsOneNumber();
                //funkcja sprawdzajaca czy data dzisiejsza
                dataCorrect = 1;
                break;
            }
            case '2':
            {
                cout << "Wprowadz date w formacie YYYY-MM-DD: ";
                //funkcja sprawdzajaca poprawnosc daty
                //temporaryInt =
                break;
            }
            default:
            {
                cout << "Nie ma takiej opcji, wybierz ponownie. ";
                dataCorrect = 0;
            }
        }




    }while (dataCorrect != 1);
    income.setCostDate(temporaryInt);

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
            cout << " Wprowadz poprawne dane. Z maksymalnymi dwoma miejscami po przecinku" <<endl;
            return -1;
        }
    }
    temporaryTwoInt = SupportMethod::convertStringToInt(temporaryTwo);
    if (temporaryTwoInt >=100)
    {
        cout << " Wprowadz poprawne dane. Z maksymalnymi dwoma miejscami po przecinku" <<endl;
        return -1;
    }
    total = temporaryOne + '.' + temporaryTwo;
    return SupportMethod::convertStringToFloat(total);
}
