/**
 * \file Actor.cpp
 *
 * \author Andrew Decrem
 */

#include "pch.h"
#include "Actor.h"
#include "Picture.h"

using namespace Gdiplus;

 /** Constructor
 * \param name The actor name */
CActor::CActor(const std::wstring& name) : mName(name)
{
    mChannel.SetName(mName);
}


/** Destructor */
CActor::~CActor()
{
}


/** Set the root drawable for the actor
* \param root Pointer to root drawable */
void CActor::SetRoot(std::shared_ptr<CDrawable> root)
{
    mRoot = root;
}
/** Draw an general actor
* \param graphics The graphics that is being drawn */
void CActor::Draw(Gdiplus::Graphics* graphics)
{
    // Don't draw if not enabled
    if (!mEnabled)
        return;

    // This takes care of determining the absolute placement
    // of all of the child drawables. We have to determine this 
    // in tree order, which may not be the order we draw.
    if (mRoot != nullptr)
        mRoot->Place(mPosition, 0);

    for (auto drawable : mDrawablesInOrder)
    {
        drawable->Draw(graphics);
    }
}

/** Hit test for actor
* \param graphics The graphics that is being drawn 
* \returns a clicked drawable object or nullptr
*/
std::shared_ptr<CDrawable> CActor::HitTest(Gdiplus::Point pos)
{
    // If not enabled or not clickable, we indicate no hit.
    if (!mClickable || !mEnabled)
        return nullptr;

    // Since this list is in drawing order, we realy want to know the last thing drawn
    // under the mouse, since it will be on top. So, we reverse iterate over the list.
    for (auto d = mDrawablesInOrder.rbegin(); d != mDrawablesInOrder.rend(); d++)
    {
        auto drawable = *d;
        if (drawable->HitTest(pos))
            return drawable;
    }

    return nullptr;
}


/**
* Add a drawable to this actor
* \param drawable The drawable to add
*/
void CActor::AddDrawable(std::shared_ptr<CDrawable> drawable)
{
    mDrawablesInOrder.push_back(drawable);
    drawable->SetActor(this);
}

void CActor::SetPicture(CPicture* picture)
{
    mPicture = picture;

    // Set the timeline for all drawables. This links the channels to
    // the timeline system.
    for (auto drawable : mDrawablesInOrder)
    {
        drawable->SetTimeline(mPicture->GetTimeline());
    }
    SetTimeline(mPicture->GetTimeline());
}
//Set keyframe
void CActor::SetKeyframe()
{
    for (auto drawable : mDrawablesInOrder)
    {
        drawable->SetKeyframe();
    }
    mChannel.SetKeyframe(mPosition);
}
//Get to keyframe
void CActor::GetKeyframe()
{
    for (auto drawable : mDrawablesInOrder)
    {
        drawable->GetKeyframe();
    }
    if (mChannel.IsValid())
    {
        mPosition = mChannel.GetPoint();
    }
}
//Set timeline
void CActor::SetTimeline(CTimeline* timeline)
{
    timeline->AddChannel(&mChannel); // add to channel
}