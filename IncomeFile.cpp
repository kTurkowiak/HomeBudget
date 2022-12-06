#include "IncomeFile.h"

void IncomeFile::readLastIncomeId()
{
    CMarkup xml;
    bool fileExists = xml.Load( "income.xml" );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        lastIncomeId = 0;
        xml.Save("income.xml");
        return;
    }
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("IncomeId");
        lastIncomeId = SupportMethod::convertStringToInt(xml.GetData());
        xml.OutOfElem();
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    if (xml.FindElem("Income") == false)
    {
        lastIncomeId = 0;
    }
}

int IncomeFile::getLastIncomeId()
{
    return lastIncomeId;
}

void IncomeFile::setLastIncomeId(int lastId)
{
    lastIncomeId = lastId;
}

void IncomeFile::addNewIncomeIntoFile(Income income)
{
    CMarkup xml;
    xml.Load( "income.xml" );
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("IncomeId", income.getCostId());
    xml.AddElem("IncomeDate", income.getCostDate());
    xml.AddElem("IncomeItem", income.getCostItem());
    xml.AddElem("IncomeAmount", SupportMethod::convertFloatToString(income.getCostAmount()));
    xml.Save("income.xml");

}


vector <Income> IncomeFile::loadIncomeCurrentLogedUser(int currentLogInUser)
{
    CMarkup xml;
    Income income;
    vector <Income> incomes;
    xml.Load( "income.xml" );
    int temporaryUserIdFromFile;
    bool fileExists = xml.Load( "income.xml" );
    if (!fileExists)
    {
        return incomes;
    }
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        temporaryUserIdFromFile = SupportMethod::convertStringToInt(xml.GetData());
        if (temporaryUserIdFromFile == currentLogInUser)
        {
            income.setUserId(temporaryUserIdFromFile);
            xml.FindElem("IncomeId");
            income.setCostId(SupportMethod::convertStringToInt(xml.GetData()));
            xml.FindElem("IncomeDate");
            income.setCostDate(SupportMethod::convertStringToInt(xml.GetData()));
            xml.FindElem("IncomeItem");
            income.setCostItem(xml.GetData());
            xml.FindElem("IncomeAmount");               //odczytuje string i zaczytuje do float
            income.setCostAmount(SupportMethod::convertStringToFloat(xml.GetData()));
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }

    return incomes;
}


