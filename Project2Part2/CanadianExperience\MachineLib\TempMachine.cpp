/**
 * \file TempMachine.cpp
 *
 * \author Andrew Decrem
 *
 * A temp machine that starts to pull things together. Similar to the actual machine recommended.
 *
 */
#include "pch.h"
#include "TempMachine.h"
#include "MachineOneFactory.h"
#include "MachineTwoFactory.h"

using namespace std;

/**
 * Constructor that sets the machine
 */
CTempMachine::CTempMachine()
{
	SetMachineNumber(1);
}

/**
 * Set Machine number, changes the machine when instructed
 * \param machine
 */
void CTempMachine::SetMachineNumber(int machine)
{
	mMachineNumber = machine;
	if (mMachineNumber == 1)
	{
		CMachineOneFactory factoryOne;
		mMachine = factoryOne.Create();
		mMachine->SetTempMachine(this);
	}
	if (mMachineNumber == 2)
	{
		CMachineTwoFactory factoryTwo;
		mMachine = factoryTwo.Create();
		mMachine->SetTempMachine(this);
	}
}


/**
 * Draw the machine
 * \param graphics 
 */
void CTempMachine::DrawMachine(Gdiplus::Graphics* graphics)
{
	mMachine->DrawMachine(graphics, mLocation.X, mLocation.Y);
}


/**
 * Set machine frame
 * Provided by website
 * \param frame 
 */
void CTempMachine::SetMachineFrame(int frame)
{
	if (frame < mFrame)
	{
		mFrame = frame;
		mMachine->AdvanceFrame(1.0 / FrameRate);
		mMachine->SetTime(mFrame * 1.0 / FrameRate);
		return;
	}

	while (mFrame < frame)
	{
		mFrame++;
		mMachine->SetTime(mFrame / FrameRate);
		mMachine->AdvanceFrame(1.0 / FrameRate);
	}
}

