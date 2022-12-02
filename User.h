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
