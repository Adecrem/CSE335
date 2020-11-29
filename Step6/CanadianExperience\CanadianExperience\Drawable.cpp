/**
 * \file Drawable.cpp
 *
 * \author Andrew Decrem
 */
#include "pch.h"
#include "Drawable.h"
#include "Actor.h"
#include "Timeline.h"

 /** Constructor */
CDrawable::CDrawable(const std::wstring& name) : mName(name)
{

}

/** Destructor */
CDrawable::~CDrawable()
{

}

/**
 * Add child to drawable
 * \param The child to add
 */
void CDrawable::AddChild(std::shared_ptr<CDrawable>child) {
    mChildren.push_back(child);
    child->SetParent(this);
}


/**
 * Set the actor using this drawable
 * \param actor Actor using this drawable
 */
void CDrawable::SetActor(CActor* actor)
{
    mActor = actor;
    mChannel.SetName(actor->GetName() + L":" + mName);
}

/** Rotate a point by a given angle.
* \param point The point to rotate
* \param angle An angle in radians
* \returns Rotated point
*/
Gdiplus::Point CDrawable::RotatePoint(Gdiplus::Point point, double angle)
{
    double cosA = cos(angle);
    double sinA = sin(angle);

    return Gdiplus::Point(int(cosA * point.X + sinA * point.Y),
        int(-sinA * point.X + cosA * point.Y));
}

/**
 * Place this drawable relative to its parent
 *
 * This works hierarchically from top item down.
 * \param offset Parent offset
 * \param rotate Parent rotation
 */
void CDrawable::Place(Gdiplus::Point offset, double rotate)
{
    // Combine the transformation we are given with the transformation
    // for this object.
    mPlacedPosition = offset + RotatePoint(mPosition, rotate);
    mPlacedR = mRotation + rotate;

    // Update our children
    for (auto drawable : mChildren)
    {
        drawable->Place(mPlacedPosition, mPlacedR);
    }
}

/**
 * Move this drawable some amount
 * \param delta The amount to move
 */
void CDrawable::Move(Gdiplus::Point delta)
{
    if (mParent != nullptr)
    {
        mPosition = mPosition + RotatePoint(delta, -mParent->mPlacedR);
    }
    else
    {
        mPosition = mPosition + delta;
    }
}
//Set timeline
void CDrawable::SetTimeline(CTimeline* timeline)
{
    timeline->AddChannel(&mChannel);
}
//Set keyframe
void CDrawable::SetKeyframe()
{
    mChannel.SetKeyframe(mRotation);
}
//Get keyframe
void CDrawable::GetKeyframe()
{
    if (mChannel.IsValid())
        mRotation = mChannel.GetAngle();
}