/**
 * \file Key.cpp
 *
 * \author Team Plessie
 */


#include "pch.h"
#include <string>
#include <memory>
#include "Key.h"
using namespace Gdiplus;
using namespace std;

const wstring KeyImageName = L"images/key.png";
/// Collision distance for the door in pixels
const double CollisionDistance = 20;

/** Key cinstructor
 * 
 * \param game Game to be played
 */
CKey::CKey(CGame* game) : CItem(game, KeyImageName)
{
    mKeyImage = unique_ptr<Gdiplus::Bitmap>(
        Bitmap::FromFile(KeyImageName.c_str()));
    if (mKeyImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/Key.png");
    }

}


/**
 * Deconstructor
 */
CKey::~CKey()
{
}

/**Draw key 
 * 
 * \param graphics Key image
 * \param scrollX Scroll offset
 */
void CKey::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    int wid = GetImage()->GetWidth();
    int hit = GetImage()->GetHeight();
    graphics->DrawImage(GetImage(),
        (int)GetX() - wid / 2, (int)GetY() - hit / 2,
        wid + 1, hit);
}

/**Draw key
 * 
 * \param graphics Key image
 */
void CKey::OnDraw(Gdiplus::Graphics* graphics)
{
    graphics->DrawImage(mKeyImage.get(), 0, 0,
        mKeyImage->GetWidth(), mKeyImage->GetHeight());
}


/** Load key
 * 
 * \param node Node to be loaded
 */
void CKey::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mKeyImage = unique_ptr<Bitmap>(Bitmap::FromFile(KeyImageName.c_str()));
    SetImage(L"key.png");
}