#include "ExpenseFile.h"

void ExpenseFile::readLastExpenseId()
{
    CMarkup xml;
    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        lastExpenseId = 0;
        xml.Save(FILE_NAME);
        return;
    }
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        lastExpenseId = SupportMethod::convertStringToInt(xml.GetData());
        xml.OutOfElem();
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    if (xml.FindElem("Expense") == false)
    {
        lastExpenseId = 0;
    }
}

int ExpenseFile::getLastExpenseId()
{
    return lastExpenseId;
}

void ExpenseFile::setLastExpenseId(int lastId)
{
    lastExpenseId = lastId;
}

void ExpenseFile::addNewExpenseIntoFile(Expense expense)
{
    CMarkup xml;
    xml.Load( FILE_NAME );
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("ExpenseId", expense.getCostId());
    xml.AddElem("ExpenseDate", expense.getCostDate());
    xml.AddElem("ExpenseItem", expense.getCostItem());
    xml.AddElem("ExpenseAmount", SupportMethod::convertFloatToString(expense.getCostAmount()));
    xml.Save(FILE_NAME);
}

vector <Expense> ExpenseFile::loadExpenseCurrentLogedUser(int currentLogInUser)
{
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    xml.Load(FILE_NAME);
    int temporaryUserIdFromFile;
    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists)
    {
        return expenses;
    }
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        temporaryUserIdFromFile = SupportMethod::convertStringToInt(xml.GetData());
        if (temporaryUserIdFromFile == currentLogInUser)
        {
            expense.setUserId(temporaryUserIdFromFile);
            xml.FindElem("ExpenseId");
            expense.setCostId(SupportMethod::convertStringToInt(xml.GetData()));
            xml.FindElem("ExpenseDate");
            expense.setCostDate(SupportMethod::convertStringToInt(xml.GetData()));
            xml.FindElem("ExpenseItem");
            expense.setCostItem(xml.GetData());
            xml.FindElem("ExpenseAmount");
            expense.setCostAmount(SupportMethod::convertStringToFloat(xml.GetData()));
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}


