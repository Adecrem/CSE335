/**
 * \file Timeline.cpp
 *
 * \author Andrew Decrem
 */
#include "pch.h"
#include "Timeline.h"
/**
 * Constructor
 */
CTimeline::CTimeline()
{

}
/** Destructor */
CTimeline::~CTimeline()
{

}


/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
*/
void CTimeline::SetCurrentTime(double t)
{
    // Set the time
    mCurrentTime = t;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}
//Add to channel
void CTimeline::AddChannel(CAnimChannel* channel)
{
    mChannels.push_back(channel);
    channel->SetTimeline(this);
}
//Delete the keyframe
void CTimeline::DeleteKeyframe()
{
    for (auto chan : mChannels)
    {
        chan->DeleteKeyframe();
    }
}