/**
 * \file TempMachine.h
 *
 * \author Andrew Decrem
 *
 * Class that represents the actual machine.
 *
 */
#pragma once
#include "Machine.h"
#include <memory>

class CBlower;

class CTempMachine : public CMachine
{
public:

	const double FrameRate = 30.0;

	///Constructor
	CTempMachine();

	///Copy constructor disabled
	CTempMachine(const CTempMachine&) = delete;

	///Assignment operator disabled
	void operator=(const CTempMachine&) = delete;

	///Draw machine
	void DrawMachine(Gdiplus::Graphics* graphics);
	
	///Set machine frame
	virtual void SetMachineFrame(int frame);

	///Set machine number
	virtual void SetMachineNumber(int machine) override;
private:

	int mFrame = 0; //< Frame
	double mTime = 0.0; //< Time

	std::shared_ptr<CBlower> mMachine = nullptr; //< shared pointer of machine
	Gdiplus::Point mLocation = Gdiplus::Point(500, 500); //< Position

	int mMachineNumber = 0; //< Machine number

};

