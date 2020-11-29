/**
 * \file Gillman.cpp
 *
 * \author Andrew Decrem
 */

#include "pch.h"

#include <memory.h>

#include <string>

#include "Aquarium.h"

#include "Gillman.h"


using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring GillmanNormalImageName = L"images/gillman.png";
const wstring GillmanAfraidImageName = L"images/gillman-afraid.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CGillman::CGillman(CAquarium* aquarium) : CItem(aquarium)
{
    //initialize both normal and afraid gillman
    mGillmanNormal = unique_ptr<Bitmap>(Bitmap::FromFile(GillmanNormalImageName.c_str()));
    if (mGillmanNormal->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += GillmanNormalImageName;
        AfxMessageBox(msg.c_str());
    }

    mGillmanAfraid = unique_ptr<Bitmap>(Bitmap::FromFile(GillmanAfraidImageName.c_str()));
    if (mGillmanNormal->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += GillmanAfraidImageName;
        AfxMessageBox(msg.c_str());
    }
}



/**
 * Draw our fish
 * \param graphics The graphics context to draw on
 */
void CGillman::Draw(Gdiplus::Graphics* graphics)
{
    double wid = mGillmanNormal->GetWidth();
    double hit = mGillmanNormal->GetHeight();
    double wid1 = mGillmanAfraid->GetWidth();
    double wid2 = mGillmanAfraid->GetHeight();
    if (afraid)//if afraid is true then draw afraid
    {
        graphics->DrawImage(mGillmanAfraid.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)mGillmanAfraid->GetWidth(), (float)mGillmanAfraid->GetHeight());
    }
    else//draw normal
    {
        graphics->DrawImage(mGillmanNormal.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)mGillmanNormal->GetWidth(), (float)mGillmanNormal->GetHeight());
    }
}


/**
 * Test to see if we hit this object with a mouse.
 * \param x X position to test
 * \param y Y position to test
 * \return true if hit.
 */
bool CGillman::HitTest(int x, int y)
{
    double wid = mGillmanNormal->GetWidth();
    double hit = mGillmanNormal->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = mGillmanNormal->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        mGillmanNormal->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
}