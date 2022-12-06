#include "Cost.h"

void Cost::setUserId (int newId)
{
    userId = newId;
}

void Cost::setCostId (int newCostId)
{
    costId = newCostId;
}

void Cost::setCostDate (int newCostDate)
{
    costDate = newCostDate;
}

void Cost::setCostItem (string newCostItem)
{
    costItem = newCostItem;
}

void Cost::setCostAmount (float newCostAmount)
{
    costAmount = newCostAmount;
}

int Cost::getUserId()
{
    return userId;
}

int Cost::getCostId ()
{
    return costId;
}

int Cost::getCostDate()
{
  return costDate;
}

string Cost::getCostItem()
{
    return costItem;
}

float Cost::getCostAmount()
{
    return costAmount;
}
