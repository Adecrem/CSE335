/**
 * \file Snow.h
 *
 * \author Andrew Decrem
 *
 * Class that represents the snow being emitted from the machine.
 *
 */
#pragma once
class CSnow
{
public:
	///Draw function
	void Draw(Gdiplus::Graphics* graphics, int x, int y);
	///Advance function
	void AdvanceFrame(double delta);
	///Point setter
	void SetP(Gdiplus::PointF point) { mPoint = point; }
	///Velocity setter
	void SetV(Gdiplus::PointF velocity) { mVelocity = velocity; }

	///Get Y coordinate
	double GetY() { return mPoint.Y; }
	///Get X coordinate
	double GetX() { return mPoint.X; }

private:

	Gdiplus::PointF mPoint; //< Point
	Gdiplus::PointF mVelocity; //< Velocity
};

