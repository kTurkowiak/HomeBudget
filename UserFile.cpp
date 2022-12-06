#include "UserFile.h"

void UserFile::saveNewUserIntoFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getUserLogin());
    xml.AddElem("Password", user.getUserPassword());
    xml.AddElem("Name", user.getUserName());
    xml.AddElem("Surname", user.getUserSurname());
    xml.Save("users.xml");
}

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    if (!fileExists)
    {
        cout << "Plik z uzytkownikami nie istnieje. Prosze o zarejestrowanie uzytkownikow" << endl;
        return users;
    }
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setUserId(SupportMethod::convertStringToInt(xml.GetData()));
        xml.FindElem("Login");
        user.setUserLogin(xml.GetData());
        xml.FindElem("Password");
        user.setUserPassword(xml.GetData());
        xml.FindElem("Name");
        user.setUserName(xml.GetData());
        xml.FindElem("Surname");
        user.setUserSurname(xml.GetData());
        users.push_back (user);
        xml.OutOfElem();
    }
    return users;
}

void UserFile::saveAllUserPassword(vector <User> users)
{

    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    xml.FindElem();
    xml.IntoElem();
    int checkedUserId;
        for (vector <User>:: iterator itr = users.begin(); itr!=users.end(); itr++)
        {
            xml.FindElem("User");
            xml.IntoElem();
            xml.FindElem("Password");
            xml.SetData(itr ->getUserPassword());
            xml.OutOfElem();
        }
        xml.Save("users.xml");

}
