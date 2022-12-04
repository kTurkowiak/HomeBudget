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



public:
    void saveNewUserIntoFile(User user);
    vector <User> loadUsersFromFile();              //do usuniecie cout'ow
    void saveAllUserPassword(vector <User> users); //do usuniecie cout'ow


};



#endif
