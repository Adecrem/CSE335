/**
 * \file Background.cpp
 *
 * \author Team Plessie
 */
#include "pch.h"
#include "Background.h"
#include "Item.h"

const wstring BackgroundImageName2 = L"images/backgroundColorGrass.png";
const wstring BackgroundImageName1 = L"images/backgroundForest.png";
const wstring BackgroundImageName3 = L"images/backgroundColorDesert";


/** Background constructor
 * 
 * \param game Game to be played
 */
CBackground::CBackground(CGame* game) : CItem(game, BackgroundImageName2)
{

}

/**
 * Deconstructor
 */
CBackground::~CBackground()
{
}

/** Draw background
 * 
 * \param graphics Image to draw
 * \param scrollX Scroll offset
 */
void CBackground::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    int wid = GetImage()->GetWidth();
    int hit = GetImage()->GetHeight();
    graphics->DrawImage(GetImage(),
        (int)GetX() - wid / 2, (int)GetY() - hit / 2,
        wid + 1, hit);
}

/** load background
 * 
 * \param node Node to load
 */
void CBackground::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    wstring id = node->GetAttributeValue(L"id", L"");
    if (id == L"i001")
    {
        mBackgroundImage = unique_ptr<Bitmap>(Bitmap::FromFile(BackgroundImageName1.c_str()));
        SetImage(L"backgroundForest.png");
    }
    else if (id == L"i002")
    {
        mBackgroundImage = unique_ptr<Bitmap>(Bitmap::FromFile(BackgroundImageName2.c_str()));
        SetImage(L"backgroundColorGrass.png");
    }
}

/** Background collision test
 * 
 * \param item Item to test for collision
 * \returns false
 */
bool CBackground::CollisionTest(CItem* item)
{
    return false;
}