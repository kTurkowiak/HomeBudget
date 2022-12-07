#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "SupportMethod.h"

using namespace std;

class UserFile
{
    const string USER_FILE_NAME;

public:
    UserFile(string userFileName)
    :USER_FILE_NAME(userFileName)
    {

    };
    void saveNewUserIntoFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUserPassword(vector <User> users);

};



#endif
