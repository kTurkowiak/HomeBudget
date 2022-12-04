#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = getNewUserData();
    users.push_back(user);
    userFile.saveNewUserIntoFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system ("pause");
}

User UserManager::getNewUserData()
{
    User user;
    user.setUserId(setIdForNewUser());
    do
    {
        cout << "Podaj login: ";
        user.setUserLogin(SupportMethod::loadLine());

    } while (didLoginExist(user.getUserLogin()) == true);
    cout << "Podaj haslo: ";
    user.setUserPassword(SupportMethod::loadLine());
    cout << "Podaj imie: ";
    user.setUserName(SupportMethod::loadLine());
    cout << "Podaj nazwisko: ";
    user.setUserSurname(SupportMethod::loadLine());
    return user;
}

int UserManager::setIdForNewUser()
{
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::didLoginExist(string login)
{
    for (int i = 0; i <(int) users.size(); i++)
    {
        if(users[i].getUserLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUser() //do pozniejszego usuniecia
{
    for (int i = 0; i <(int) users.size(); i++)
    {
        cout << "User ID: " << users[i].getUserId() << endl;
        cout << "User login: " << users[i].getUserLogin() << endl;
        cout << "User haslo: " << users[i].getUserPassword() << endl;
        cout << "User Imie: " << users[i].getUserName() << endl;
        cout << "User Nazwisko: " << users[i].getUserSurname() << endl;
    }
}

void UserManager::userLogIn()
{
    User user;
    string login = "", password = "";
    cout << endl << "Podaj login: ";
    login = SupportMethod::loadLine();
    vector <User>:: iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getUserLogin() == login)
        {
            for (int trialNumber = 3; trialNumber >0; trialNumber--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << trialNumber << ": ";
                password = SupportMethod::loadLine();
                if (itr -> getUserPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    currentLogInUser = itr -> getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            currentLogInUser = 0;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    currentLogInUser = 0;
}

bool UserManager::didUserLogIn()
{
    if (currentLogInUser > 0)
    {
        return true;
    }
    else return false;
}
