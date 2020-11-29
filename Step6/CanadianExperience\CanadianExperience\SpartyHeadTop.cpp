/**
 * \file SpartyHeadTop.cpp
 *
 * \author Andrew Decrem
 */
#include "pch.h"
#include "SpartyHeadTop.h"

using namespace std;
using namespace Gdiplus;
/** Constructor */
CSpartyHeadTop::CSpartyHeadTop(const std::wstring& name, const std::wstring& filename) : CHeadTop(name, filename)
{
}

/** Destructor */
CSpartyHeadTop::~CSpartyHeadTop()
{

}

void CSpartyHeadTop::Draw(Gdiplus::Graphics* graphics)
{
	CHeadTop::Draw(graphics);
	DrawEye(Point(30, 105), graphics);
	DrawEye(Point(75, 105), graphics);
}