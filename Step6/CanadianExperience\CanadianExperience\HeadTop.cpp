/**
 * \file HeadTop.cpp
 *
 * \author Andrew Decrem
 */
#include "pch.h"
#include "HeadTop.h"
#include "Timeline.h"

using namespace Gdiplus;

/**Constructor
*\param name Name of the object
*\param filename Filename of the image
*/
CHeadTop::CHeadTop(const std::wstring& name, const std::wstring& filename) : CImageDrawable(name, filename)
{

}

/** Destructor */
CHeadTop::~CHeadTop() {

}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/** General head top
* \param graphics The graphics that is being drawn
*/
void CHeadTop::Draw(Gdiplus::Graphics* graphics)
{
    CImageDrawable::Draw(graphics);
}

/** Drawing eye
* \param p The point to draw the eye
* \param graphics The graphics that is being drawn
* \returns a clicked drawable object or nullptr
*/
void CHeadTop::DrawEye(Gdiplus::Point p, Gdiplus::Graphics* graphics)
{
    SolidBrush brush(Color::Black);
    float wid = 15.0f;
    float hit = 20.0f;

    int x = TransformPoint(p).X;
    int y = TransformPoint(p).Y;

    auto state = graphics->Save();
    graphics->TranslateTransform(x, y);
    graphics->RotateTransform((float)(-mPlacedR * RtoD));
    graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
    graphics->Restore(state);
}

/** Draw eyebrow
* \param p1 where the line starts
* \param p2 Where the line stops
* \param graphics The graphics that is being drawn
*/
void CHeadTop::DrawEyebrow(Gdiplus::Point p1, Gdiplus::Point p2, Gdiplus::Graphics* graphics)
{
    Pen eyebrowPen(Color::Black, 2);
    auto state = graphics->Save();
    graphics->DrawLine(&eyebrowPen, TransformPoint(p1), TransformPoint(p2));
    graphics->Restore(state);
}

//Set keyframe
void CHeadTop::SetKeyframe()
{
    CDrawable::SetKeyframe();
    mChannel.SetKeyframe(GetPosition());
}
//Get keyframe
void CHeadTop::GetKeyframe()
{
    CDrawable::GetKeyframe();
    if (mChannel.IsValid())
    {
        SetPosition(mChannel.GetPoint());
    }
}
//Set timeline
void CHeadTop::SetTimeline(CTimeline* timeline)
{
    CDrawable::SetTimeline(timeline);
    timeline->AddChannel(&mChannel);
}