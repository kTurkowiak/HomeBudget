#ifndef COST_H
#define COST_H

#include <string>
#include <vector>

using namespace std;

class Cost
{
    int userId;
    int costId;
    int costDate;
    string costItem;
    float costAmount;

public:
    Cost (int userId = 0, int costId = 0, int costDate = 0, string costItem = "",  float costAmount = 0)
    {
        this -> userId = userId;
        this -> costId = costId;
        this -> costDate = costDate;
        this -> costItem = costItem;
        this -> costAmount = costAmount;
    };

    void setUserId (int newId);
    void setCostId (int newCostId);
    void setCostDate (int newCostDate);
    void setCostItem (string newCostItem);
    void setCostAmount (float newCostAmount);
    int getUserId();
    int getCostId ();
    int getCostDate();
    string getCostItem();
    float getCostAmount();
    friend class BudgetManager;
};



#endif
