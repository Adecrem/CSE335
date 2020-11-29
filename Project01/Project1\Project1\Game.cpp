/**
 * \file Game.cpp
 *
 * \author Team Plessie
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"
#include "Gnome.h"
#include "XmlNode.h"
#include "Door.h"
#include "Platform.h"
#include "Villain.h"
#include "Wall.h"
#include "Money.h"
#include "TuitionUp.h"
#include "Background.h"
#include "ChildView.h"

using namespace std;
using namespace xmlnode;


/// Game area height in virtual pixels
const static int Height = 1024;

/** Draw game
 * 
 * \param graphics Image to be drawn
 * \param width Width of image
 * \param height Height of image
 * \param gnome Gnome for game
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height, std::shared_ptr<CGnome> gnome)
{
    //
    // Automatic Scaling
    //
    mScale = float(height) / float(Height);
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;

    //graphics->DrawImage(mBackground.get(), 0, 0,
    //    mBackground->GetWidth(), mBackground->GetHeight());

    // Compute the amount to scroll in the X dimension
    auto xOffset = (float)-gnome->GetX() + virtualWidth / 2.0f;

    //xOffset = min(xOffset, 500);
    auto save = graphics->Save();
    graphics->TranslateTransform(xOffset, 0);
    //scoreboard.Draw(graphics, virtualWidth / 10);
    //graphics->Restore(save);
    //mGnomeImage->Draw(graphics, xOffset);

    for (auto item : mItems)
    {
        item->Draw(graphics, xOffset);
    }
    graphics->Restore(save);
    scoreboard.Draw(graphics, virtualWidth / 20);
}

/**
 * Game constructor
 */
CGame::CGame()
{
    mBackground = unique_ptr<Gdiplus::Bitmap>(
        Bitmap::FromFile(L"images/backgroundColorDesert.png"));
    if (mBackground->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/backgroundColorGrass.png");
    }
}

/**
 * Deconstructor
 */
CGame::~CGame()
{

}

/** Add item to mItems
 * 
 * \param item Item to be added
 */
void CGame::Add(std::shared_ptr<CItem> item)
{

    mItems.push_back(item);
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
    scoreboard.Update(elapsed);
}

/** Load game
 * 
 * \param filename Game to be loaded
 */
void CGame::Load(const std::wstring& filename)
{
    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        Clear();

        //
        // Traverse the children of the root
        // node of the XML document in memory!!!!
        //
        for (auto big_node : root->GetChildren())
        {
            auto name = big_node->GetName();
            if (big_node->GetType() == NODE_ELEMENT && name == L"items")
            {
                for (auto node : big_node->GetChildren())
                {
                    XmlItem(node);
                }
            }
        }
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

}

/**
*  Clear the items data.
*
* Deletes all known items in the city.
*/
void CGame::Clear()
{
    mItems.clear();
}


/**
*  Handle a tile node.
* \param node Pointer to XML node we are handling
*/
void CGame::XmlItem(const std::shared_ptr<CXmlNode>& node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item. What type?
    wstring id = node->GetAttributeValue(L"id", L"");
    if (id == L"i001")
    {
        item = make_shared<CBackground>(this);
    }
    else if (id == L"i002")
    {
        item = make_shared<CBackground>(this);
    }
    else if (id == L"i003")
    {
        item = make_shared<CPlatform>(this);
    }
    else if (id == L"i004")
    {
        item = make_shared<CPlatform>(this);
    }
    else if (id == L"i005")
    {
        item = make_shared<CPlatform>(this);
    }
    else if (id == L"i006")
    {
        item = make_shared<CWall>(this);
    }
    else if (id == L"i007")
    {
        item = make_shared<CWall>(this);
    }
    else if (id == L"i008")
    {
        item = make_shared<CMoney>(this);
    }
    else if (id == L"i009")
    {
        item = make_shared<CMoney>(this);
    }
    else if (id == L"i010")
    {
        item = make_shared<CTuitionUp>(this);
    }
    else if (id == L"i011")
    {
        item = make_shared<CDoor>(this);
    }
    else if (id == L"i012")
    {
        item = make_shared<CVillain>(this);
    }
    else if (id == L"i013")
    {
        item = make_shared<CVillain>(this);
    }

    if (item != nullptr)
    {
        item->XmlLoad(node);
        Add(item);
    }
}


/** Key down function
 * 
 * \param nChar Given parameter
 * \param nRepCnt Given parameter
 * \param nFlags Given parameter
 */
void CGame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    for (auto item : mItems)
    {
        item->OnKeyDown(nChar, nRepCnt, nFlags);
    }
}

/** Key Up function
 * 
 * \param nChar Given parameter
 * \param nRepCnt Given parameter
 * \param nFlags Given parameter
 */
void CGame::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    for (auto item : mItems)
    {
        item->OnKeyUp(nChar, nRepCnt, nFlags);
    }
}

/** Game collision test
 * 
 * \param item Item to check for collision
 * \returns Object that collided
 */
std::shared_ptr<CItem> CGame::CollisionTest(CItem* item)
{
    for (shared_ptr<CItem> object : mItems)
    {
        
        if (item == object.get())
        {
            continue;
        }
        
        if (object->CollisionTest(item))
        {
            return object;
        }
    }
    return nullptr;
}

/** Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CGame::Accept(CItemVisitor* visitor)
{
    for (auto tile : mItems)
    {
        tile->Accept(visitor);
    }
}

