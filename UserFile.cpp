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
        //cout << "z pliku user.UserId: " << user.getUserId() <<endl;           //do pozniejszego usuniecia
        xml.FindElem("Login");
        user.setUserLogin(xml.GetData());
        //cout << "z pliku user.getUserId: " << user.getUserLogin() <<endl;     //do pozniejszego usuniecia
        xml.FindElem("Password");
        user.setUserPassword(xml.GetData());
        //cout << "z pliku user.getUserPassword: " << user.getUserPassword() <<endl;    //do pozniejszego usuniecia
        xml.FindElem("Name");
        user.setUserName(xml.GetData());
        //cout << "z pliku user.getUserName: " << user.getUserName() <<endl;        //do pozniejszego usuniecia
        xml.FindElem("Surname");
        user.setUserSurname(xml.GetData());
        //cout << "z pliku user.getUserSurname: " << user.getUserSurname() <<endl;  //do pozniejszego usuniecia
        users.push_back (user);
        xml.OutOfElem();
    }
    return users;
}

void UserFile::saveAllUserPassword(vector <User> users) //do usuniecie cout'ow
{

    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    xml.FindElem();
    xml.IntoElem();
    //cout << "IntoElem1: " << xml.GetData() <<endl;
    int checkedUserId;
        for (vector <User>:: iterator itr = users.begin(); itr!=users.end(); itr++)
        {
            xml.FindElem("User");
            xml.IntoElem();
            //cout << "IntoElem2: " << xml.GetData()<<endl; /do pozniejszego usuniecia
            xml.FindElem("Password");
            //cout << "FindElem(Password): " << xml.GetData() <<endl;  //do pozniejszego usuniecia
            //cout<< "Wszedlem w wektor"<<endl;
            //cout<< "itr id ->"<< itr ->getUserId()<<endl;
            //cout<< "itr password ->"<< itr ->getUserPassword()<<endl;
            xml.SetData(itr ->getUserPassword());
            //cout << "FindElem(PasswordSetData) po zmianie hasla: " << xml.GetData() <<endl;
            xml.OutOfElem();
        }
        xml.Save("users.xml");

}
