/**
 * \file HaroldHeadTop.cpp
 *
 * \author Andrew Decrem
 */
#include "pch.h"
#include "HaroldHeadTop.h"


using namespace Gdiplus;
/** Constructor */
CHaroldHeadTop::CHaroldHeadTop(const std::wstring& name, const std::wstring& filename) : CHeadTop(name, filename) 
{

}

/** Destructor */
CHaroldHeadTop::~CHaroldHeadTop() {

}

/** Draw the head of harold
* \param graphics The graphics that is being drawn
*/
void CHaroldHeadTop::Draw(Gdiplus::Graphics* graphics)
{
	CHeadTop::Draw(graphics);
	DrawEyebrow(Point(32, 63), Point(46, 61), graphics);
	DrawEyebrow(Point(64, 59), Point(77, 61), graphics);
	DrawEye(Point(42, 79), graphics);
	DrawEye(Point(69, 79), graphics);
}
//Saw an outline of how to make this from  Interact