/**
 * \file Money.cpp
 *
 * \author Team Plessie
 */


#include "pch.h"
#include "Money.h"
using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


const wstring money100 = L"images/money100.png";
const wstring money1000 = L"images/money1000.png";

/** Money constructor
 * 
 * \param game Game to be played
 */
CMoney::CMoney(CGame* game) : CItem(game, money1000)
{
}

/**
 * Destructor
 */
CMoney::~CMoney()
{

}

/** Draw money
 * 
 * \param graphics Money image
 * \param scrollX Scroll offest
 */
void CMoney::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    int wid = GetImage()->GetWidth();
    int hit = GetImage()->GetHeight();
    graphics->DrawImage(GetImage(),
        (int)GetX() - wid / 2, (int)GetY() - hit / 2,
        wid + 1, hit);
}


/** Money load
 * 
 * \param node Node to be loaded
 */
void CMoney::XmlLoad(const shared_ptr<CXmlNode>& node)
{
    CItem::XmlLoad(node);
    wstring id = node->GetAttributeValue(L"id", L"");
    if (id == L"i008")
    {
        mMoneyImage = unique_ptr<Bitmap>(Bitmap::FromFile(money100.c_str()));
        SetImage(L"money100.png");
        mIsHundred = true;
    }
    else if (id == L"i009")
    {
        mMoneyImage = unique_ptr<Bitmap>(Bitmap::FromFile(money1000.c_str()));
        SetImage(L"money1000.png");
        mIsThousand = true;
    }
}


/** Money collision test
 * 
 * \param item Item money may be colliding with
 * \returns Boolean if it collided
 */
bool CMoney::CollisionTest(CItem* item)
{
    if (CItem::CollisionTest(item))
    {
        //add to score
        return false; //shouldnt be here... placeholder for other code
    }
    return false;
}
