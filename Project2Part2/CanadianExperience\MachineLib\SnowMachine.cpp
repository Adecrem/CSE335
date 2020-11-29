/**
 * \file SnowMachine.cpp
 *
 * \author Andrew Decrem
 *
 * SnowMachine class that represents the snow machine and does the majority of the calculations
 *
 */
#include "pch.h"
#include "SnowMachine.h"
#include "Sink.h"
#include "Blower.h"
#include "TempMachine.h"

/// Average amount of snow created per rotation
const double SnowPerRotation = 1000;

/// Variance in how much snow is created
const double SnowVariancePerSecond = 100;

/// Range of the random angle snow will be thrown in
const double SnowAngleVariance = 0.1;

/// Angle range for the end of the snow machine in radians.
const double SnowMachineAngleRange = 0.25;

/// Offset to end of snow blower from middle in pixels
const double SnowBlowerOffset = 100;

/// Random variance in the snowblower offset
const double SnowBlowerOffsetVariance = 5;

/// Minimum snow particle velocity
const double SnowMinimumVelocity = 90;

/// Maximum snow particle velocity
const double SnowMaximumVelocity = 110;

using namespace std;

/**
 * Generate a uniform distribution random number from fmValue to toValue
 * \param fmValue Minimum value to generate
 * \param toValue Maximum value to generate
 * \return Random number
 */
double CSnowMachine::Random(double fmValue, double toValue)
{
	std::uniform_real_distribution<> distribution(fmValue, toValue);
	return distribution(mRandom);
}


/**
 * Constructor for snow machine
 *
 * Constants given
 */
CSnowMachine::CSnowMachine()
{
	mSink.SetComponent(this);
	int wid = 120;
	int hit = 174;
	this->Rectangle(-wid / 2, 60, wid, hit);
	std::random_device rd;	// Generates a random seed
	mRandom.seed(rd());		// Seed the random number generator
}


/**
 * Update sink
 * \param sink 
 *
 * Saw something on interact that pointed to this
 */
void CSnowMachine::Update(CSink* sink)
{
	double lessSnow = mSink.GetRotation() - mDriveRotation;
	Blower(lessSnow);
	double rotation = mSink.GetRotation();
	mDriveRotation = rotation;
}

/**
 * Advance function that will then delete the snow
 * Used a list as website suggested
 * Suggested on an interact post, solved my final problem.
 * \param delta
 */
void CSnowMachine::AdvanceFrame(double delta)
{
	std::vector<std::list<CSnow>::iterator>snowDelete; //list to delete

	for (auto deleted = mSnow.begin(); deleted != mSnow.end(); deleted++)
	{
		auto snow = deleted;

		snow->AdvanceFrame(delta);

		if (snow->GetY() > 200)
		{
			snowDelete.push_back(deleted);
		}
	}
	for (auto deleted : snowDelete)
	{
		mSnow.erase(deleted);
	}
}


/**
 * Draw the snow
 * \param graphics 
 * \param x 
 * \param y 
 */
void CSnowMachine::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	for (auto snow : mSnow)
	{
		snow.Draw(graphics, x, y);
	}
	CComponent::Draw(graphics, x, y);
}


/**
 * Set the rotation
 * Thought back to aquarium when we were required to make it turn.
 * \param angle 
 */
void CSnowMachine::SetRotation(double ang)
{
	CComponent::SetRotation(ang);
	if (ang < 0)
	{
		this->SetImage(L"images/blowerL.png");
	}
	else if (ang > 0)
	{
		this->SetImage(L"images/blowerR.png");
	}
}


/**
 * Blower function that actually blows the snow
 * Mostly provided by website
 *
 * \param rotation 
 */
void CSnowMachine::Blower(double rotation)
{
	auto num = (int)(rotation * (SnowPerRotation + Random(-SnowVariancePerSecond, SnowVariancePerSecond)));

	for (int i = 0; i < num; i++) {
		CSnow snow;
		// GetRotation gets the rotation of the snow machine.
		// This code computes a vector to the emitting end of the
		// snow machine. The random value means that position is over
		// the entire end of the machine, not just a single point.
		auto angle = GetRotation() * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
		auto dx = sin(angle);
		auto dy = -cos(angle);
		auto angle1 = angle + Random(-SnowAngleVariance, SnowAngleVariance);
		auto dx1 = sin(angle1);
		auto dy1 = -cos(angle1);
		double offset = SnowBlowerOffset + Random(-SnowBlowerOffsetVariance, SnowBlowerOffsetVariance);
		double velocity = Random(SnowMinimumVelocity, SnowMaximumVelocity);
		Gdiplus::PointF snowPosition((float)(GetPosition().X + dx * offset), (float)(GetPosition().Y + dy * offset));
		Gdiplus::PointF snowVelocity((float)(dx1 * velocity), (float)(dy1 * velocity));
		snow.SetP(snowPosition);
		snow.SetV(snowVelocity);
		mSnow.push_back(snow);
	}
}