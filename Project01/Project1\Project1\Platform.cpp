/**
 * \file Platform.cpp
 *
 * \author Team Plessie
 */



#include "pch.h"
#include "Platform.h"
using namespace Gdiplus;
using namespace std;


const wstring platform = L"images/platformIndustrial_059.png"; ///Platform image
const wstring platform2 = L"images/platformIndustrial_060.png";  ///Platform image
const wstring platform3 = L"images/platformIndustrial_057.png";  ///Platform image
const wstring platform4 = L"images/platformIndustrial_061.png";  ///Platform image
const wstring grass = L"images/grass.png";  ///Platform grass image
const wstring grassLeft = L"images/grassLeft.png"; ///Platform grass image
const wstring grassMid = L"images/grassMid.png"; ///Platform grass image
const wstring grassRight = L"images/grassRight.png"; ///Platform grass image
const wstring snow = L"images/snow.png"; ///Platform snow image
const wstring snowLeft = L"images/snowLeft.png"; ///Platform snow image
const wstring snowRight = L"images/snowRight.png"; ///Platform snow image
const wstring snowMid = L"images/snowMid.png"; ///Platform snow image


/** Platform constructor
 * 
 * \param game Game to be played
 */
CPlatform::CPlatform(CGame* game) : CItem(game, platform)
{
}


/**
 * Destructor
 */
CPlatform::~CPlatform()
{
}


/** Draw platform 
 * 
 * \param graphics Platform image
 * \param scrollX Scroll offset
 */
void CPlatform::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
	int wid = GetPlatformWidth();
	int hit = GetPlatformHeight();
	graphics->DrawImage(GetImage(),
		(int)GetX() - wid / 2, (int)GetY() - hit / 2,
		wid + 1, hit);

}


/** Platform loading
 * 
 * \param node Node to be loaded
 */
void CPlatform::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	mHeight = node->GetAttributeIntValue(L"height", 0);
	mWidth = node->GetAttributeIntValue(L"width", 0);
	CItem::XmlLoad(node);
	wstring id = node->GetAttributeValue(L"id", L"");
	if (id == L"i003")
	{
		mPlatformImage = unique_ptr<Bitmap>(Bitmap::FromFile(grass.c_str()));
		SetImage(L"grass.png");
	}
	else if (id == L"i004")
	{
		mPlatformImage = unique_ptr<Bitmap>(Bitmap::FromFile(snow.c_str()));
		SetImage(L"snow.png");
	}
	else if (id == L"i005")
	{
		mPlatformImage = unique_ptr<Bitmap>(Bitmap::FromFile(platform.c_str()));
		SetImage(L"platformIndustrial_059.png");
	}
}
