/**
 * \file MachineDrawable.cpp
 *
 * \author Andrew Decrem
 *
 * Machine drawable, drawing the machine in canadian experience.
 */


#include "pch.h"
#include "MachineDrawable.h"
#include "MachineFactory.h"
#include "Timeline.h"

CMachineDrawable::~CMachineDrawable()
{

}


/**
 * Creating the machine
 * \param name 
 * \param machineNum 
 */
CMachineDrawable::CMachineDrawable(const std::wstring& name, int machineNum) : CDrawable(name)
{
	CMachineFactory factory;
	mMachine = factory.CreateMachine();
	mMachine->SetMachineNumber(machineNum);
	mMachine->SetMachineFrame(0);
}


/**
 * Draw the actual machine
 * \param graphics 
 */
void CMachineDrawable::Draw(Gdiplus::Graphics* graphics)
{
	float scale = .8f;
	auto save = graphics->Save();
	graphics->TranslateTransform((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
	graphics->ScaleTransform(scale, scale);
	mMachine->SetMachineFrame(mMachineAnimChannelPoint.GetTimeline()->GetCurrentFrame());
	mMachine->DrawMachine(graphics);
	mMachine->SetLocation(mPlacedPosition.X, mPlacedPosition.Y);
	graphics->Restore(save);
}


/**
 * Set the timeline to work with the machine
 * \param timeline 
 */
void CMachineDrawable::SetTimeline(CTimeline* timeline)
{
	CDrawable::SetTimeline(timeline);
	timeline->AddChannel(&mMachineAnimChannelPoint);
}



/**
 * Set the position of the machine.
 * \param position 
 */
void CMachineDrawable::SetPosition(Gdiplus::Point position)
{
	mMachine->SetLocation(position.X, position.Y);
}

void CMachineDrawable::SetKeyFrame(int frame)
{
    mFrame = frame;
}