/**
 * \file Money.h
 *
 * \author Team Plessie
 *
 * Money object class
 */


#pragma once
#include "Level.h"
#include<string>
#include "Item.h"
#include "XmlNode.h"

class CMoney : public CItem
{

public:

    ///  Default constructor (disabled)
    CMoney() = delete;

    CMoney(CGame* game);
    ///  Copy constructor (disabled)
    CMoney(const CMoney&) = delete;

    ~CMoney();

	virtual void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

    void OnDraw(Gdiplus::Graphics* graphics);

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    wstring MoneyImageName = L"images/money100.png";

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMoney(this); }

    bool CheckHundred() { return mIsHundred; }

    virtual bool CollisionTest(CItem* item) override;
    //comment
private:
    ///  Amount for money item 
    int mHundred = 100; ///< initialize 100

    int mThousand = 1000; ///< initalize 1000

    bool mIsHundred = false; ///< is the money 100 

    bool mIsThousand = false; ///< is the money 1000

    std::unique_ptr<Gdiplus::Bitmap> mMoneyImage; ///< Background image to use
};

