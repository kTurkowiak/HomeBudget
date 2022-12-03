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
    vector <User> loadUsersFromFile();


};



#endif
