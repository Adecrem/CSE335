/**
 * \file Door.cpp
 *
 * \author Team Plessie
 */

#include <string>
#include "pch.h"
#include "Door.h"
#include <memory>
using namespace Gdiplus;
using namespace std;

const wstring DoorImageName = L"images/door.png";

/// Collision distance for the door in pixels
const double CollisionDistance = 20;

/** Door constructor
 * 
 * \param game Game to be played
 */
CDoor::CDoor(CGame* game) : CItem(game, DoorImageName)
{
    mDoorImage = unique_ptr<Gdiplus::Bitmap>(
        Bitmap::FromFile(DoorImageName.c_str()));
    if (mDoorImage->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/Key.png");
    }
}



/**
 * Deconstructor
 */
CDoor::~CDoor()
{
}

/** Draw door
 * 
 * \param graphics Door image
 * \param scrollX Scroll offset
 */
void CDoor::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    int wid = GetImage()->GetWidth();
    int hit = GetImage()->GetHeight();
    graphics->DrawImage(GetImage(),
        (int)GetX() - wid / 2, (int)GetY() - hit / 2,
        wid + 1, hit);
}

/** Door collision test
 * 
 * \param item Item to test for collision on
 * \returns Boolean if collided
 */
bool CDoor::CollisionTest(CItem* item)
{
    // Collision for door is different
    double dx = item->GetX() - GetX();
    double dy = item->GetY() - GetY();
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < CollisionDistance)
    {
        return true;
    }

    return false;
}

/** Load door
 * 
 * \param node Node to load
 */
void CDoor::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mDoorImage = unique_ptr<Bitmap>(Bitmap::FromFile(DoorImageName.c_str()));
    SetImage(L"door.png");
}