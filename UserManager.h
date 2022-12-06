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
    UserManager (string userFileName)
    : userFile(userFileName)
    {
        users = userFile.loadUsersFromFile();
        //showAllUser();                                   //do pozniejszego usuniecia
    }
    int getCurrentLogInUser();

    void userRegistration();
    void userLogIn();
    void changePassword();
    void userLogOut();
    bool didUserLogIn();


};



#endif
