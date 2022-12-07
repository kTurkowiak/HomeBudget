#include "BudgetManager.h"

void BudgetManager::addNewIncome()
{
    Income income;
    int lastIncomeId = incomeFile.getLastIncomeId();
    income = getNewIncomeData(lastIncomeId);
    incomeFile.addNewIncomeIntoFile(income);
    incomeFile.setLastIncomeId(lastIncomeId + 1);
    incomes.push_back(income);
}

void BudgetManager::addNewExpense()
{
    Expense expense;
    int lastExpenceId = expenseFile.getLastExpenseId();
    expense = getNewExpenceData(lastExpenceId);
    expenseFile.addNewExpenseIntoFile(expense);
    expenseFile.setLastExpenseId(lastExpenceId + 1);
    expenses.push_back(expense);
}

Income BudgetManager::getNewIncomeData(int lastIncomeId)
{
    system("cls");
    Income income;
    char choose;
    income.setUserId(CURRENT_LOGEDIN_USER);
    income.setCostId(lastIncomeId + 1);
    float temporaryFloat;
    string temporaryString;
    int temporaryInt;
    bool dataCorrect = 0;
    do
    {
        cout << "Jaka date chcesz ustawic?" << endl <<endl;
        cout << "1. Data dzisiejsza: " << dateManager.getTotalTodayDateAsString() << "?" << endl;
        cout << "2. Data wlasna" << endl;
        cout << "---------------------------" << endl;
        cout << "Twoj wybor: ";
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
                cout << "Wprowadz date w formacie YYYY-MM-DD. Za separatory mozesz uzyc kropki, myslinika lub przecinka :";
                temporaryString = SupportMethod::loadLine();
                temporaryInt = checkDateCorrectInt(temporaryString);
                dataCorrect = 1;
                if (temporaryInt == -1)
                {
                    dataCorrect = 0;
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
            dataCorrect = 0;
        }
    } while (dataCorrect != 1);
    income.setCostAmount(temporaryFloat);
    return income;
}

Expense BudgetManager::getNewExpenceData(int lastExpeseId)
{
    system("cls");
    Expense expense;
    char choose;
    expense.setUserId(CURRENT_LOGEDIN_USER);
    expense.setCostId(lastExpeseId + 1);
    float temporaryFloat;
    string temporaryString;
    int temporaryInt;
    bool dataCorrect = 0;
    do
    {
        cout << "Jaka date chcesz ustawic?" << endl <<endl;
        cout << "1. Data dzisiejsza: " << dateManager.getTotalTodayDateAsString() << "?" << endl;
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
                cout << "Wprowadz date w formacie YYYY-MM-DD. Za separatory mozesz uzyc kropki, myslinika lub przecinka :";
                temporaryString = SupportMethod::loadLine();
                temporaryInt = checkDateCorrectInt(temporaryString);
                dataCorrect = 1;
                if (temporaryInt == -1)
                {
                    dataCorrect = 0;
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
    expense.setCostDate(temporaryInt);
    cout << "Podaj nazwe wydatku: ";
    expense.setCostItem(SupportMethod::loadLine());
    do
    {
        dataCorrect = 1;
        cout << "Podaj wielkosc wydatku: " ;
        temporaryString = (SupportMethod::loadLine());
        temporaryFloat = BudgetManager::checkDataCorrectFloat(temporaryString);
        if (temporaryFloat == -1)
        {
            dataCorrect = 0;
        }
    } while (dataCorrect != 1);
    expense.setCostAmount(temporaryFloat);
    return expense;
}

float BudgetManager::checkDataCorrectFloat (string number)
{
    int stringLength =  number.length();
    string zlotych, pennies, total;
    bool dotOrComma = 0;
    int penniesInt;
    for (int i = 0; i< stringLength; i++)
    {
        if ((isdigit(number[i]) == true) && (dotOrComma == 0))
        {
            zlotych = zlotych + number[i];
        }
        else if ((((int) number[i]) == 44) || ((int) number[i]) == 46)
        {
            dotOrComma = 1;
        }
        else if ((isdigit(number[i]) == true) && (dotOrComma == 1))
        {
            pennies = pennies + number[i];;
        }
        else
        {
            cout << " Wprowadz poprawne dane. Z maksymalnymi dwoma miejscami po przecinku" << endl;
            return -1;
        }
    }
    penniesInt = SupportMethod::convertStringToInt(pennies);
    if (penniesInt >= 100)
    {
        cout << "Wprowadz poprawne dane. Z maksymalnymi dwoma miejscami po przecinku" << endl;
        return -1;
    }
    total = zlotych + '.' + pennies;
    return SupportMethod::convertStringToFloat(total);
}

int BudgetManager::checkDateCorrectInt (string number)
{
    int stringLength =  number.length();
    string year, month, day, total;
    int yearInt, monthInt, dayInt, totalInt;
    bool dotOrCommaOrDash = 0;
    bool dotOrCommaOrDash2 = 0;
    for (int i = 0; i< stringLength; i++)
    {
        if (((isdigit(number[i])) == true) && (dotOrCommaOrDash == 0) && (dotOrCommaOrDash2 == 0))
        {
            year = year + number[i];
        }
        else if ((((((int) number[i]) >= 44) || ((int) number[i]) <= 47)) && ((dotOrCommaOrDash == 0) && (dotOrCommaOrDash2 == 0)))
        {
            dotOrCommaOrDash = 1;
        }
        else if (((isdigit(number[i])) == true) && (dotOrCommaOrDash == 1)&& (dotOrCommaOrDash2 == 0))
        {
            month = month + number[i];
        }
        else if ((((((int) number[i]) >= 44) || ((int) number[i]) <= 47)) && ((dotOrCommaOrDash == 1) && (dotOrCommaOrDash2 == 0)))
        {
            dotOrCommaOrDash2 = 1;
        }
        else if (((isdigit(number[i])) == true) && (dotOrCommaOrDash == 1)&& (dotOrCommaOrDash2 == 1))
        {
            day = day + number[i];
        }
        else
        {
            cout << "Wprowadz poprawne dane. Pamietaj, aby wstawiac kropki, przecinka, lub myslnika miedzy sekcje daty" << endl;
            return -1;
        }
    }
    yearInt = SupportMethod::convertStringToInt(year);
    monthInt = SupportMethod::convertStringToInt(month);
    dayInt = SupportMethod::convertStringToInt(day);
    if ((yearInt <=1000) || (yearInt > dateManager.getTodayYear()))
    {
        cout << "Wprowadz poprawne dane. Nie mozesz podac daty przekraczajaca dzisiejsza, lub ponizej roku 1000" << endl;
        return -1;
    }
    if ((monthInt > 12) || (monthInt < 0))
    {
        cout << "Wprowadz poprawne dane. Rok ma tylko dwanascie miesiecy" << endl;
        return -1;
    }
    if (dateManager.isDateValid(dayInt, monthInt, yearInt)==false)
    {
        cout << "Wprowadz poprawne dane. Wybrany miesiac nie ma tyle dni" << endl;
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
        cout << "Nie mozesz wprowadzic daty wiekszej niz dzisiejsza" <<endl;
        return -1;
    }
    return -1;
}

void BudgetManager::sortingIncomeAndExpense()
{
    sort (incomes.begin(), incomes.end(), [](const Income &lower, const Income &higher)
    {
        return lower.costDate < higher.costDate;
    });
    sort (expenses.begin(), expenses.end(), [](const Expense &lower, const Expense &higher)
    {
        return lower.costDate < higher.costDate;
    });
}

void BudgetManager::showBalanceForCurrentMonth()
{
    system("cls");
    sortingIncomeAndExpense();
    float totalSum = 0, incomeSum = 0, expenseSum = 0;
    int fullTodayDateAsOneNumber = dateManager.getFullTodayDateAsOneNumber();
    int firstDayOfCurrentMonth = dateManager.getFirstDayOfCurrentMonth();
    cout << endl << "W tym miesiacu miales przychod" << endl;
    for (int i = 0; i < (int) incomes.size(); i++)
    {
        if (((incomes[i].costDate) <= fullTodayDateAsOneNumber) && ((incomes[i].costDate) >= firstDayOfCurrentMonth))
        {
            cout << "Z tytulu: " << incomes[i].costItem << " Kwota: " << incomes[i].costAmount << "PLN" << endl;
            incomeSum = incomeSum + incomes[i].costAmount;
        }
    }
    cout << "---------------------------" << endl;
    cout << "Laczny przychod wyniosl: " << incomeSum << endl;
    cout << endl <<"W tym miesiacu wydales" << endl;
    for (int i = 0; i < (int) expenses.size(); i++)
    {
        if (((expenses[i].costDate) <= fullTodayDateAsOneNumber) && ((expenses[i].costDate) >= firstDayOfCurrentMonth))
        {
            cout << "Z tytulu: " << expenses[i].costItem << " Kwota: " << expenses[i].costAmount << "PLN" << endl;
            expenseSum = expenseSum + expenses[i].costAmount;
        }
    }
    cout << "---------------------------" << endl;
    cout << "Laczne wydatki wyniosly: " << expenseSum << endl;
    totalSum = incomeSum - expenseSum;
    cout << "---------------------------" << endl;
    cout << "Sumarycznie :" << totalSum << "PLN" <<endl << endl;
    system("Pause");
}

void BudgetManager::showBalanceForPreviousMonth()
{
    system("cls");
    sortingIncomeAndExpense();
    float totalSum = 0 , incomeSum = 0, expenseSum = 0;
    int fullDatePreviousMonthFirstDay = dateManager.getFirstDayOfPreviousMonth();
    int firstDayOfCurrentMonth = dateManager.getFirstDayOfCurrentMonth();
    cout << endl << "W poprzednim miesiacu miales przychod" << endl;
    for (int i = 0; i < (int) incomes.size(); i++)
    {
        if (((incomes[i].costDate) <= (firstDayOfCurrentMonth - 1)) && ((incomes[i].costDate) >= fullDatePreviousMonthFirstDay))
        {
            cout << "Z tytulu: " << incomes[i].costItem << " Kwota: " << incomes[i].costAmount << "PLN" << endl;
            incomeSum = incomeSum + incomes[i].costAmount;
        }
    }
    cout << "---------------------------" << endl;
    cout << "Laczny przychod wyniosl: " << incomeSum << endl;
    cout << endl <<"W poprzednim miesiacu wydales" << endl;
    for (int i = 0; i < (int) expenses.size(); i++)
    {
        if (((expenses[i].costDate) <= (firstDayOfCurrentMonth - 1)) && ((expenses[i].costDate) >= fullDatePreviousMonthFirstDay))
        {
            cout << "Z tytulu: " << expenses[i].costItem << " Kwota: " << expenses[i].costAmount << "PLN" << endl;
            expenseSum = expenseSum + expenses[i].costAmount;
        }
    }
    cout << "---------------------------" << endl;
    cout << "Laczne wydatki wyniosly: " << expenseSum << endl;
    totalSum = incomeSum - expenseSum;
    cout << "---------------------------" << endl;
    cout << "Sumarycznie :" << totalSum << "PLN" <<endl << endl;
    system("Pause");
}

void BudgetManager::showBalanceForChoosenPeriod()
{
    system("cls");
    sortingIncomeAndExpense();
    float totalSum = 0 , incomeSum = 0, expenseSum = 0;
    bool dateCorrect = 0;
    string firstDateInput = "", secondDateInput = "";
    int temporaryIntFirstDateInput = 0, temporaryIntSecondDateInput = 0, inverse = 0;
    do
    {
        cout << "Wprowadz date OD kiedy pokazac podumowanie w formacie YYYY-MM-DD: " << endl;
        firstDateInput = SupportMethod::loadLine();
        temporaryIntFirstDateInput = checkDateCorrectInt(firstDateInput);
        dateCorrect = 1;
        if (temporaryIntFirstDateInput == -1)
        {
            dateCorrect = 0;
        }
    }while (dateCorrect != 1);
    dateCorrect = 0;
    do
    {
        cout << "Wprowadz date DO kiedy pokazac podumowanie w formacie YYYY-MM-DD: " << endl;
        secondDateInput = SupportMethod::loadLine();
        temporaryIntSecondDateInput = checkDateCorrectInt(secondDateInput);
        dateCorrect = 1;
        if (temporaryIntSecondDateInput == -1)
        {
            dateCorrect = 0;
        }
    }while (dateCorrect != 1);
    if (temporaryIntFirstDateInput > temporaryIntSecondDateInput)  //in case of date reveresal
    {
        inverse = temporaryIntFirstDateInput;
        temporaryIntFirstDateInput = temporaryIntSecondDateInput;
        temporaryIntSecondDateInput = inverse;
    }
    cout << endl << "W wyznaczonym przedziale czasu miales przychod" << endl;
    for (int i = 0; i < (int) incomes.size(); i++)
    {
        if (((incomes[i].costDate) <= (temporaryIntSecondDateInput)) && ((incomes[i].costDate) >= temporaryIntFirstDateInput))
        {
            cout << "Z tytulu: " << incomes[i].costItem << " Kwota: " << incomes[i].costAmount << "PLN" << endl;
            incomeSum = incomeSum + incomes[i].costAmount;
        }
    }
    cout << "---------------------------" << endl;
    cout << "Laczny przychod wyniosl: " << incomeSum << endl;
    cout << endl <<"W wyznaczonym przedziale czasu wydales" << endl;
    for (int i = 0; i < (int) expenses.size(); i++)
    {
        if (((expenses[i].costDate) <= (temporaryIntSecondDateInput)) && ((expenses[i].costDate) >= temporaryIntFirstDateInput))
        {
            cout << "Z tytulu: " << expenses[i].costItem << " Kwota: " << expenses[i].costAmount << "PLN" << endl;
            expenseSum = expenseSum + expenses[i].costAmount;
        }
    }
    cout << "---------------------------" << endl;
    cout << "Laczne wydatki wyniosly: " << expenseSum << endl;
    totalSum = incomeSum - expenseSum;
    cout << "---------------------------" << endl;
    cout << "Sumarycznie :" << totalSum << "PLN" <<endl << endl;
    system("Pause");
}
