/**
 * \file Motor.h
 *
 * \author Andrew Decrem
 *
 * Class that represents the motor in the machine.
 *
 */

#pragma once
#include <memory>
#include "Component.h"
#include "Source.h"
class CMotor : public CComponent
{
public:
	const static int Size = 80;

	///Default motor
	CMotor(double diameter);
	///virtual destructor
	virtual ~CMotor();
	///Copy constructor disabled
	CMotor(const CMotor&) = delete;
	///Assignment operator disabled
	void operator=(const CMotor&) = delete;
	///Draw function that draws with graphics and coordinates
	virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);
	///Set the time of the motor
	void SetRotation(double time);
	//Set Speed
	void SetSpeed(double speed);
	/// Getter for source
	CSource* GetSource() { return &mSource; }

private:
	double mSize;
	double mSpeed;
	double mRPM;
	CPolygon mShaft; //< polygon for shaft
	CSource mSource; //< Source
};

