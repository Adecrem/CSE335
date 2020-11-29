/**
 * \file AnimChannelPoint.h
 *
 * \author Andrew Decrem
 *
 * Animated channel point
 */
#pragma once
#include "AnimChannel.h"

class CAnimChannelPoint : public CAnimChannel
{
public:
	///Constructor
	CAnimChannelPoint();
	///Destructor
	virtual ~CAnimChannelPoint();
	/// Disable copy
	CAnimChannelPoint(const CAnimChannelPoint&) = delete;
	///Disable Assignment
	void operator=(const CAnimChannelPoint&) = delete;
	///Point getter
	Gdiplus::Point GetPoint() { return mPoint; }
	///Set the key frame
	void SetKeyframe(Gdiplus::Point point);
	///Keyframe point class basically taken from angle
	class KeyframePoint : public CAnimChannel::Keyframe
	{
	public:
		///Constructor, given in angle
		KeyframePoint(CAnimChannelPoint* channel, Gdiplus::Point point) : Keyframe(channel), mChannel(channel), mPoint(point) {}

		///Point getter
		Gdiplus::Point GetPoint() { return mPoint; }
		///Given use's
		virtual void UseAs1() override { mChannel->mKeyFrame1 = this; }
		virtual void UseAs2() override { mChannel->mKeyFrame2 = this; }
		virtual void UseOnly() override { mChannel->mPoint = mPoint; }
	private:
		///set point
		Gdiplus::Point mPoint = Gdiplus::Point(0, 0);
		///channel
		CAnimChannelPoint* mChannel;

	};
protected:
	///Given tween
	void Tween(double t);
private:
	Gdiplus::Point mPoint = Gdiplus::Point(0, 0); ///< Setting point
	KeyframePoint* mKeyFrame1 = nullptr; ///< First keyframe
	KeyframePoint* mKeyFrame2 = nullptr; ///< seconds keyframe
};

