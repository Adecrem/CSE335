/**
 * \file AddMoneyVisitor.cpp
 *
 * \author Team Plessie
 */
#include "pch.h"
#include "AddMoneyVisitor.h"
#include "Money.h"

/**
 * Deconstructor
 */
CAddMoneyVisitor::~CAddMoneyVisitor()
{
}

/**Visit function
 * 
 * \param money Money item
 */
void CAddMoneyVisitor::VisitMoney(CMoney* money)
{
	auto hundredbill = money->CheckHundred();
	if (hundredbill) 
	{
		mAmount += 100;
	}
	else
	{
		mAmount += 1000;
	}
}
