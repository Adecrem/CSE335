/**
 * \file Wall.cpp
 *
 * \author Team Plessie
 */



#include "pch.h"
#include "Wall.h"
using namespace Gdiplus;
using namespace std;


const wstring wall1 = L"images/wall1.png";

const wstring wall2 = L"images/wall2.png";


/** Constructor
 * 
 * \param game Game to play on
 */
CWall::CWall(CGame* game) : CItem(game, wall1)
{
}



/**
 * Destructor
 */
CWall::~CWall()
{
}

/** Draws wall
 * 
 * \param graphics Wall image
 * \param scrollX Scroll offset
 */
void CWall::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
	int wid = GetWallWidth();
	int hit = GetWallHeight();
	graphics->DrawImage(GetImage(),
		(int)GetX() - wid / 2 , (int)GetY() - hit / 2,
		wid + 1, hit);

}

/** Load wall from XML
 * 
 * \param node Node to be loaded
 */
void CWall::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	mHeight = node->GetAttributeIntValue(L"height", 0);
	mWidth = node->GetAttributeIntValue(L"width", 0);
	CItem::XmlLoad(node);
	wstring id = node->GetAttributeValue(L"id", L"");
	if (id == L"i006")
	{
		mWallImage = unique_ptr<Bitmap>(Bitmap::FromFile(wall1.c_str()));
		SetImage(L"wall1.png");
	}
	else if (id == L"i007")
	{
		mWallImage = unique_ptr<Bitmap>(Bitmap::FromFile(wall2.c_str()));
		SetImage(L"wall2.png");
	}
}