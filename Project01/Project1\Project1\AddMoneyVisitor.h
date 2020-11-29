/**
 * \file AddMoneyVisitor.h
 *
 * \author Team Plessie
 *
 * Visitor for money
 */
#pragma once
#include "ItemVisitor.h"

class CAddMoneyVisitor : public CItemVisitor
{
public:
    CAddMoneyVisitor() { mAmount = 0; }

    virtual ~CAddMoneyVisitor();

    /** Get the amount of money
     * \returns Amount of money */
    int GetAmount() const { return mAmount; }

    void VisitMoney(CMoney* money);
private:
    /// amount
    int mAmount = 0;
};

