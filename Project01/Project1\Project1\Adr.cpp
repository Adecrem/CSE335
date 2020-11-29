/**
 * \file Adr.cpp
 *
 * \author Team Plessie
 */
#include "pch.h"
#include <string>
#include <memory>
#include "Adr.h"
using namespace Gdiplus;
using namespace std;

const wstring AdrImageName = L"images/SpecialImage.png";

/// Collision distance for the door in pixels
const double CollisionDistance = 20;


/** Adr constructor
 * 
 * \param game Game to be played
 */
CAdr::CAdr(CGame* game) : CItem(game, AdrImageName)
{
    mAdrImage = unique_ptr<Gdiplus::Bitmap>(
        Bitmap::FromFile(AdrImageName.c_str()));
    if (mAdrImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/Key.png");
    }
}


/**
 * Deconstructor
 */
CAdr::~CAdr()
{
}

/** Draw Adr
 * 
 * \param graphics Image to draw
 * \param scrollX Scroll offset
 */
void CAdr::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    int wid = GetImage()->GetWidth();
    int hit = GetImage()->GetHeight();
    graphics->DrawImage(GetImage(),
        (int)GetX() - wid / 2, (int)GetY() - hit / 2,
        wid + 1, hit);

}

/**Adr loading
 * 
 * \param node Node to load
 */
void CAdr::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mAdrImage = unique_ptr<Bitmap>(Bitmap::FromFile(AdrImageName.c_str()));
    SetImage(L"SpecialImage.png");
}