#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UserFile.h"
#include "SupportMethod.h"

using namespace std;

class UserManager
{
    vector <User> users;
    UserFile userFile;
    int currentLogInUser;



    User getNewUserData();
    int setIdForNewUser();
    bool didLoginExist(string login);
    void showAllUser();



public:
    UserManager ()
    {
        users = userFile.loadUsersFromFile();
        showAllUser();

    }

    void userRegistration();
    void userLogIn();
    //changePassword();
    //logOut();
    bool didUserLogIn();


};



#endif
