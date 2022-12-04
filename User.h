#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    int userId;
    string userLogin;
    string userPassword;
    string userName;
    string userSurname;

public:
    User (int userId = 0, string userLogin = "", string userPassword = "",  string userName = "", string userSurname = "")
    {
        this -> userId = userId;
        this -> userLogin = userLogin;
        this -> userPassword = userPassword;
        this -> userName = userName;
        this -> userSurname = userSurname;
    };

    void setUserId(int newId);
    void setUserLogin(string newLogin);
    void setUserPassword(string newUserPassword);
    void setUserName(string newUserName);
    void setUserSurname(string newUserSurname);
    int getUserId();
    string getUserLogin();
    string getUserPassword();
    string getUserName();
    string getUserSurname();



};

#endif
