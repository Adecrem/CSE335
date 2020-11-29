/**
 * \file SnowMachine.h
 *
 * \author Andrew Decrem
 *
 * Class the represents the actual snow machine.
 *
 */
#pragma once
#include <random>
#include <list>
#include "Component.h"
#include "Sink.h"
#include "Snow.h"
class CSnowMachine : public CComponent
{
public:
	///Constructor
	CSnowMachine();

	///Sink update
	void Update(CSink* sink) override;

	///Virtual draw function
	virtual void Draw(Gdiplus::Graphics* graphics, int x, int y) override;

	///Set rotation
	virtual void SetRotation(double ang) override;

	///Get sink
	CSink* GetSink() { return &mSink; }

	///Advance function
	virtual void AdvanceFrame(double delta) override;

private:

	void Blower(double rotation); //< Blower function for snow

	double Random(double fmValue, double toValue); //< Random function provided

	CSink mSink; //< sink

	double mDriveRotation = 0; //< drive rotation

	std::list<CSnow> mSnow; //< Snow in list as suggested in website

	std::mt19937 mRandom; //< Random provided by website
};

