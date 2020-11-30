/**
 * \file Pulley.h
 *
 * \author Andrew Decrem
 *
 * Class that represents the pulley in the machine.
 *
 */
#pragma once
#include <memory>
#include "Component.h"
#include "Sink.h"
#include "Source.h"
class CPulley : public CComponent
{
public:

	///Constructor
	CPulley(double diameter);

	///Virtual destructor
	virtual ~CPulley();

	///disable default
	CPulley() = delete;

	///disable copy constructor
	CPulley(const CPulley&) = delete;

	///Disable assignment operator
	void operator=(const CPulley&) = delete;

	///Virtual draw function
	virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);

	///Get sink
	CSink *GetSink() { return &mSink; }

	///Get source
	CSource* GetSource() { return &mSource; }

	///Setter for rotation
	void SetRotation(double rotation) override;

	///How to drive the pulley
	void DrivePulley(std::shared_ptr<CPulley> pulley);

	///Get the diameter
	double GetDiameter() { return mDiameter; }

	///Update the sink
	virtual void Update(CSink* sink);

private:

	double mDiameter = 0; //< the diameter

	CSink mSink; //< The sink

	CSource mSource; //< The source

	std::shared_ptr<CPulley> mPulley; //< shared pointer to pulley

};

