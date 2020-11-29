/**
 * \file Snow.cpp
 *
 * \author Andrew Decrem
 *
 * Snow class, class that creates the snow.
 *
 */

#include "pch.h"
#include "Snow.h"
using namespace std;
using namespace Gdiplus;

const float Gravity = 15;


/**
 * Advance function
 * Suggested on website
 * \param delta
 */
void CSnow::AdvanceFrame(double delta)
{
    mVelocity = PointF(mVelocity.X, mVelocity.Y + Gravity * (float)delta);
    mPoint = PointF(mPoint.X + mVelocity.X * (float)delta, mPoint.Y + mVelocity.Y * (float)delta);
}


/**
 * Draw function
 * \param graphics 
 * \param x 
 * \param y 
 */
void CSnow::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	SolidBrush brush(Color::White);
	graphics->FillRectangle(&brush, (int)mPoint.X + x, (int)mPoint.Y + y, 2, 2);
}
