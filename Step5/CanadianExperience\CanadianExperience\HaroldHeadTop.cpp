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
	DrawEyebrow(Point(25, 55), Point(45, 55), graphics);
	DrawEyebrow(Point(80, 60), Point(60, 55), graphics);
	DrawEye(Point(35, 70), graphics);
	DrawEye(Point(70, 70), graphics);
}
//Saw an outline of how to make this from  Interact