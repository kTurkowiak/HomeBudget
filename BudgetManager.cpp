#include "BudgetManager.h"

void BudgetManager::addNewIncome()
{
    Income income;
    int lastId = incomeFile.getLastIncomeId();
    income = getNewIncomeData(lastId);
    incomeFile.addNewIncomeIntoFile(income);
    incomeFile.setLastIncomeId(lastId+1);
    incomes.push_back(income);
}

Income BudgetManager::getNewIncomeData(int lastId)
{
    system("cls");
    Income income;
    char choose;
    income.setUserId(CURRENT_LOGEDIN_USER);
    income.setCostId(lastId+1);
    float temporaryFloat;
    string temporaryString;
    int temporaryInt;
    bool dataCorrect = 0;

    do{
        cout << "Jaka date chcesz ustawic?" << endl <<endl;
        cout << "1. Data dzisiejsza: " << dateManager.getTotalTodayDateAsString() << "?"<< endl;
        cout << "2. Data wlasna" << endl;
        cout << "---------------------------" << endl;
        cout<< "Twoj wybor: ";
        choose = SupportMethod::loadChar();
        switch (choose)
        {
            case '1':
            {
                temporaryInt = dateManager.getFullTodayDateAsOneNumber();
                dataCorrect = 1;
                break;
            }
            case '2':
            {
                cout << "Wprowadz date w formacie YYYY.MM.DD: ";
                temporaryString = SupportMethod::loadLine();
                temporaryInt = checkDataCorrectInt(temporaryString);
                dataCorrect = 1;
                if (temporaryInt == -1)
                {
                    dataCorrect=0;
                }
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
        temporaryFloat = BudgetManager::checkDataCorrectFloat(temporaryString);
        if (temporaryFloat == -1)
        {
            dataCorrect=0;
        }
    } while (dataCorrect != 1);
    income.setCostAmount(temporaryFloat);

    return income;
}


float BudgetManager::checkDataCorrectFloat (string number)
{
    int stringLength =  number.length();
    string zlotych, pennies, total;
    char temporaryCharacter;
    int temporaryCharacterInt, penniesInt;
    bool dotOrComma = 0;
    for (int i = 0; i< stringLength; i++)
    {
        temporaryCharacter = number[i];
        temporaryCharacterInt = (int) temporaryCharacter;
        if ((temporaryCharacterInt>=48) && (temporaryCharacterInt <=57) && (dotOrComma == 0))
        {
            zlotych = zlotych + temporaryCharacter;
        }
        else if ((temporaryCharacterInt == 44) ||(temporaryCharacterInt == 46))
        {
            dotOrComma = 1;
        }
        else if ((temporaryCharacterInt>=48) && (temporaryCharacterInt <=57) && (dotOrComma == 1))
        {
            pennies = pennies + temporaryCharacter;
        }
        else
        {
            cout << " Wprowadz poprawne dane. Z maksymalnymi dwoma miejscami po przecinku" <<endl;
            return -1;
        }
    }
    penniesInt = SupportMethod::convertStringToInt(pennies);
    if (penniesInt >=100)
    {
        cout << " Wprowadz poprawne dane. Z maksymalnymi dwoma miejscami po przecinku" <<endl;
        return -1;
    }
    total = zlotych + '.' + pennies;
    return SupportMethod::convertStringToFloat(total);
}


int BudgetManager::checkDataCorrectInt (string number)
{
    int stringLength =  number.length();
    string year, month, day, total;
    char temporaryCharacter;
    int temporaryCharacterInt, yearInt, monthInt, dayInt, totalInt;
    bool dotOrComma = 0;
    bool dotOrComma2 = 0;
    for (int i = 0; i< stringLength; i++)
    {
        temporaryCharacter = number[i];
        temporaryCharacterInt = (int) temporaryCharacter;
        if ((temporaryCharacterInt>=48) && (temporaryCharacterInt <=57) && (dotOrComma == 0) && (dotOrComma2 == 0))
        {
            year = year + temporaryCharacter;
        }
        else if ((temporaryCharacterInt == 44) ||(temporaryCharacterInt == 46)&& (dotOrComma == 0) && (dotOrComma2 == 0))
        {
            dotOrComma = 1;
        }
        else if ((temporaryCharacterInt>=48) && (temporaryCharacterInt <=57) && (dotOrComma == 1)&& (dotOrComma2 == 0))
        {
            month = month + temporaryCharacter;
        }
        else if ((temporaryCharacterInt == 44) ||(temporaryCharacterInt == 46)&& (dotOrComma == 1) && (dotOrComma2 == 0))
        {
            dotOrComma2 = 1;
        }
        else if ((temporaryCharacterInt>=48) && (temporaryCharacterInt <=57) && (dotOrComma == 1)&& (dotOrComma2 == 1))
        {
            day = day + temporaryCharacter;
        }
        else
        {
            cout << " Wprowadz poprawne dane. Pamietaj, aby wstawiac kropki miedzy sekcje daty" <<endl;
            return -1;
        }
    }
    yearInt = SupportMethod::convertStringToInt(year);
    monthInt = SupportMethod::convertStringToInt(month);
    dayInt = SupportMethod::convertStringToInt(day);

    if ((yearInt <=1000) || (yearInt > dateManager.getTodayYear()))
    {
        cout << "Wprowadz poprawne dane. Nie mozesz podac daty przekraczajaca dzisiejsza, lub ponizej roku 1000" <<endl;
        return -1;
    }
    if ((monthInt > 12) || (monthInt < 0))
    {
        cout << "Wprowadz poprawne dane. Rok ma tylko dwanascie miesiecy" <<endl;
        return -1;
    }
    if (dateManager.isDateValid(dayInt, monthInt, yearInt)==false)
    {
        cout << "Wprowadz poprawne dane. Wybrany miesiac nie ma tyle dni" <<endl;
        return -1;
    }

    year = SupportMethod::convertIntToString(yearInt);
    if (monthInt<10)
    {
        month = '0' + SupportMethod::convertIntToString(monthInt);
    }
    else
    {
        month = SupportMethod::convertIntToString(monthInt);
    }
    if (dayInt<10)
    {
        day = '0' + SupportMethod::convertIntToString(dayInt);
    }
    else
    {
        day = SupportMethod::convertIntToString(dayInt);
    }
    total = year + month + day;
    totalInt = SupportMethod::convertStringToInt(total);
    if (totalInt <= dateManager.getFullTodayDateAsOneNumber())
    {
        return SupportMethod::convertStringToInt(total);
    }
    else
    {
        cout << "Nie mozesz wprowadzic daty wiekszej niz dzisiejsza" <<endl; //cos nie dziala
        return -1;
    }
    return -1;
}

void BudgetManager::showAllIncome() //do pozniejszego usuniecia
{
    for (int i = 0; i <(int) incomes.size(); i++)
    {
        cout << "User Id: " << incomes[i].getUserId() << endl;
        cout << "Income Id: " << incomes[i].getCostId() << endl;
        cout << "Income date: " << incomes[i].getCostDate() << endl;
        cout << "Income title: " << incomes[i].getCostItem() << endl;
        cout << "Income amount: " << incomes[i].getCostAmount() << endl;
    }
}
