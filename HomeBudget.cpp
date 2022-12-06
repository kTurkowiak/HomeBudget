#include "HomeBudget.h"

char HomeBudget::userMenuChoose()
{
    char choose;
    //system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = SupportMethod::loadChar();
    return choose;
}

char HomeBudget::mainMenuChoose()
{
    char choose;
    //system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj nowy przychod" << endl;
    cout << "2. Dodaj nowy wydatek" << endl;
    cout << "3. Pokaz bilans z aktualnego miesiaca" << endl;
    cout << "4. Pokaz bilans z poprzedniego miesiaca" << endl;
    cout << "5. Pokaz bilans z wybranego zakresu dat" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = SupportMethod::loadChar();
    return choose;
}

void HomeBudget::userRegistration()
{
    userManager.userRegistration();
}

void HomeBudget::userLogIn()
{
    userManager.userLogIn();
    if (userManager.didUserLogIn())
    {
        budgetManager = new BudgetManager(userManager.getCurrentLogInUser(), INCOME_FILE_NAME ,EXPENSE_FILE_NAME );
    }
}

bool HomeBudget::didUserLogIn()
{
    return userManager.didUserLogIn();
}

void HomeBudget::userLogOut()
{
    userManager.userLogOut();
}

void HomeBudget::addNewIncome()
{
    budgetManager->addNewIncome();
}

void HomeBudget::addNewExpense()
{
    budgetManager->addNewExpense();
}

void HomeBudget::changePassword()
{
    userManager.changePassword();
}

void HomeBudget::showAllIncome() //do pozniejszego usuniecia
{
    budgetManager->showAllIncome();
    cout<< "Pokazuje zapisane w wektorze Income"<< endl <<endl;
    budgetManager->showAllIncome();
    cout<< "Pokazuje zapisane w wektorze Expense"<< endl <<endl;
    budgetManager->showAllExpense();

}
