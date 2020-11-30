/**
 * \file Motor.cpp
 *
 * \author Andrew Decrem
 *
 * Motor class that represents a motor controlling everything.
 *
 */
#include "pch.h"
#include "Motor.h"
using namespace std;

/**
 *  Motor with diameter
 * \param diameter 
 */
CMotor::CMotor(double diameter)
{
    mShaft.SetImage(L"images/shaft.png");
	mSize = diameter;
	CenteredSquare(diameter);
	double radius = diameter / 2;
	mShaft.Circle(radius);

}

/**
 * Destructor
 */
CMotor::~CMotor()
{

}

/**
 * Set speed for motor so it runs correctly. Based on provided factory code.
 * \param time
 */
void CMotor::SetSpeed(double speed)
{
    mSpeed = speed;
}



/**
 * Set rotation given time provided
 * \param time 
 */
void CMotor::SetRotation(double time)
{
    mRPM = time * mSpeed;
    mShaft.SetRotation(mRPM);
    mSource.SetRotation(mRPM);
}



/**
 * Draw function for motor, using graphics and axis
 * \param graphics 
 * \param x 
 * \param y 
 */
void CMotor::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	CComponent::Draw(graphics, x, y);
	mShaft.DrawPolygon(graphics, x + GetPosition().X, y + GetPosition().Y);
}
