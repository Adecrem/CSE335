/**
 * \file Item.cpp
 *
 * \author Team Plessie
 */


#include "pch.h"
#include "Item.h"
#include "XmlNode.h"

using namespace std;

/// The directory containing the file images
const std::wstring CItem::ImagesDirectory = L"images/";


/** Item constructor
 * 
 * \param game Game to be played
 * \param filename File to be loaded
 */
CItem::CItem(CGame* game, const std::wstring& filename) : mGame(game)
{
    mFile = filename;
    mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    if (mItemImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
}

/**
 * Deconstructor
 */
CItem::~CItem()
{
}

/** Draw item
 * 
 * \param graphics Item image
 * \param ScrollX Scroll offset
 */
void CItem::Draw(Gdiplus::Graphics* graphics, int ScrollX)
{
    wstring filename = ImagesDirectory + mFile;
    mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    graphics->DrawImage(mItemImage.get(),
        float(GetX() + wid / 2), float(GetY() - hit / 2),
        -(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
}

/**
* brief Load the attributes for an item node.
*
* This is the  base class version that loads the attributes
* common to all items. Override this to load custom attributes
* for specific items.
*
* \param node The Xml node we are loading the item from
*/
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mX = node->GetAttributeIntValue(L"x", 0);
    mY = node->GetAttributeIntValue(L"y", 0);
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const std::wstring& file)
{
    if (!file.empty())
    {
        wstring filename = ImagesDirectory + file;
        mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mItemImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mItemImage.release();
    }

    mFile = file;
}

/**
 *  Test to see if we hit this object with a mouse.
 * \param x X position to test
 * \param y Y position to test
 * \return true if hit.
 */
bool CItem::HitTest(int x, int y)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image.
    // Subtracting the center makes x, y relative to the center of 
    // the image. Adding half the size makes x, y relative to the top 
    // corner of the image.
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = mItemImage->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        mItemImage->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
}

/** Item collision test
 * 
 * \param item Item that may be colliding
 * \returns Boolean if collision occured
 */
bool CItem::CollisionTest(CItem* item)
{
    // Border for the item
    auto itemLeft = item->GetX() - item->GetWidth() / 2;
    auto itemRight = item->GetX() + item->GetWidth() / 2;
    auto itemTop = item->GetY() - item->GetHeight() / 2;
    auto itemBottom = item->GetY() + item->GetHeight() / 2;

    // For us
    auto ourLeft = GetX() - GetWidth() / 2;
    auto ourRight = GetX() + GetWidth() / 2;
    auto ourTop = GetY() - GetHeight() / 2;
    auto ourBottom = GetY() + GetHeight() / 2;

    // Test for all of the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight < itemLeft ||  // Completely to the left
        ourLeft > itemRight ||  // Completely to the right
        ourTop > itemBottom ||  // Completely below
        ourBottom < itemTop)    // Completely above
    {
        return false;
    }

    return true;
}