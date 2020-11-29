/**
 * \file Fish.cpp
 *
 * \author Andrew Decrem
 */


#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"
#include "XmlNode.h"
using namespace Gdiplus;
using namespace std;


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;
const double MaxSpeedY = 50;
const double MinSpeedX = 10;
const double MinspeedY = 10;

CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
    CItem(aquarium, filename)
{
    CFish::mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
    CFish::mSpeedY = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
}


/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
        GetY() + mSpeedY * elapsed);
    //reverse if hits left or right side
    if ((mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth()) || (mSpeedX < 0 && GetX() <= GetAquarium()->GetWidth()))
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }
    if ((mSpeedY > 0 && GetY() >= GetAquarium()->GetWidth()) || (mSpeedY < 0 && GetY() <= GetAquarium()->GetWidth()))
    {
        mSpeedY = -mSpeedY;
        SetMirror(mSpeedY < 0);
    }
}

