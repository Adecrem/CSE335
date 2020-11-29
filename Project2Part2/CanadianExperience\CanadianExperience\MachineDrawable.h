/**
 * \file MachineDrawable.h
 *
 * \author Andrew Decrem
 *
 * Drawable class in Canadian experience to get the machine to  actually draw.
 *
 */


#pragma once
#include "Drawable.h"
#include "Machine.h"
#include "AnimChannelPoint.h"

class CMachineDrawable : public CDrawable
{
public:
	///Virtual destructor
	virtual ~CMachineDrawable();

	///Default constructor disables
	CMachineDrawable() = delete;

	///Copy constructor disabled
	CMachineDrawable(const CMachineDrawable&) = delete;

	///Assignment operator disabled
	void operator=(const CMachineDrawable&) = delete;

	///Initialize drawable machine
	CMachineDrawable(const std::wstring& name, int machineNum);

	///Actual draw function
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	///Timeline function
	virtual void SetTimeline(CTimeline* timeline) override;

	///Hit test, false and according to interact we dont need to implement it.
	virtual bool HitTest(Gdiplus::Point position) override { return false; }

	///Set position.
	virtual void SetPosition(Gdiplus::Point position);


	///Set Key frame
	virtual void SetKeyFrame(int frame);


private:
	
	std::shared_ptr<CMachine> mMachine; //< shared pointer of machine
	CAnimChannelPoint mMachineAnimChannelPoint; //< Animated channel

	CTimeline* mTimeline = nullptr;

	int mFrame = 0; //< frame count

};

