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

    User getNewUserData();
    int setIdForNewUser();
    bool didLoginExist(string login);
    void showAllUser();


public:
    UserManager ()
    {
        showAllUser(); //do pozniejszego usuniecia
    }

    void userRegistration();
    //userLogIn();
    //changePassword();
    //logOut();
    //didUserLogIn();


};



#endif
