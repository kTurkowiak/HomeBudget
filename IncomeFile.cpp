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
