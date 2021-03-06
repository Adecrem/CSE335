/**
 * \file AnimChannelPoint.cpp
 *
 * \author Andrew Decrem
 */
#include "pch.h"
#include "AnimChannelPoint.h"

using namespace Gdiplus;
using namespace std;
/** Constructor */
CAnimChannelPoint::CAnimChannelPoint()
{

}
/** Destructor */
CAnimChannelPoint::~CAnimChannelPoint()
{

}

/**
* Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param angle Angle for the keyframe.
*/
void CAnimChannelPoint::SetKeyframe(Gdiplus::Point point)
{
    // Create a keyframe of the appropriate type
    // Telling it this channel and the angle
    shared_ptr<KeyframePoint> keyframe =
        make_shared<KeyframePoint>(this, point);

    // Insert it into the collection
    InsertKeyframe(keyframe);
}

/**
 * Compute an angle that is an interpolation between two keyframes
 *
 * This function is called after Use1 and Use2, so we have pointers to
 * to valid keyframes of the type KeyframeAngle. This function does the
 * tweening.
 * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
 * interpolate between.
 */
void CAnimChannelPoint::Tween(double t)
{
    Point a = mKeyFrame1->GetPoint();
    Point b = mKeyFrame2->GetPoint();
    Point c(int(a.X + t * (b.X - a.X)), int(a.Y + t * (b.Y - a.Y)));
    mPoint = c;
}