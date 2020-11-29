/**
 * \file ViewTimeline.cpp
 *
 * \author Andrew Decrem
 */


#include "pch.h"
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "Picture.h"
#include "Timeline.h"
#include "MainFrm.h"


using namespace std;
using namespace Gdiplus;


IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)

/// The window height in pixels
const int WindowHeight = 60;

/// The spacing from the top of the 
/// window to the top of the tick marks in pixels
const int BorderTop = 20;

/// Space to the left of the scale in pixels
const int BorderLeft = 10;

/// Space to the right of the scale in pixels
const int BorderRight = 10;

/// The spacing between ticks on the timeline in pixels
const int TickSpacing = 3;

/// The length of a short tick mark in pixels
const int TickShort = 10;

/// The length of a long tick mark in pixels
const int TickLong = 20;

/** Constructor */
CViewTimeline::CViewTimeline()
{
    mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer-down.png"));
    assert(mPointer->GetLastStatus() == Ok);
}

/** Destructor */
CViewTimeline::~CViewTimeline()
{
}

/** Update observer
*/
void CViewTimeline::UpdateObserver()
{
    Invalidate();
    UpdateWindow();
}

/** Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
    CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window 
 * \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
    // Get the timeline
    CTimeline* timeline = GetPicture()->GetTimeline();

    // Set the scroll system correctly
    CSize sizeTotal(timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, WindowHeight);
    SetScrollSizes(MM_TEXT, sizeTotal);

    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context
    Pen pen(Color(0, 128, 0), 1);
    graphics.DrawRectangle(&pen, 10, 10, 200, 60);

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 16);

    SolidBrush brush(Color(0, 0, 0));
    graphics.DrawString(L"Timeline!",  // String to draw
        -1,         // String length, -1 means it figures it out 
        &font,      // The font to use
        PointF(15, 15),   // Where to draw
        &brush);    // The brush to draw the text with

    CString time = CTime::GetCurrentTime().Format("%H:%M:%S");
    graphics.DrawString(time,  // String to draw
        -1,         // String length, -1 means it figures it out 
        &font,      // The font to use
        PointF(15, 40),   // Where to draw
        &brush);    // The brush to draw the text with

    CRect rect;
    GetClientRect(&rect);
    int hit = rect.Height();
    int wid = rect.Width();
}

void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
{
    // Convert mouse coordinates to logical coordinates
    CClientDC dc(this);
    OnPrepareDC(&dc);
    dc.DPtoLP(&point);
    CTimeline* timeline = GetPicture()->GetTimeline();

    if (mMovingPointer == true && MK_LBUTTON == true && nFlags == true)
    {
        double time = double(point.x = BorderLeft) / (timeline->GetFrameRate() * TickSpacing);
        if (time > timeline->GetDuration()) {
            time = timeline->GetDuration();
        }
        else if (time < 0) {
            time = 0;
        }
        else {
            mMovingPointer = false;
        }
    }
    UpdateObserver();
    __super::OnMouseMove(nFlags, point);
}



void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
{
    // Convert mouse coordinates to logical coordinates
    CClientDC dc(this);
    OnPrepareDC(&dc);
    dc.DPtoLP(&point);

    int x = point.x;

    // Get the timeline
    CTimeline* timeline = GetPicture()->GetTimeline();
    int pointerX = (int)(timeline->GetCurrentTime() *
        timeline->GetFrameRate() * TickSpacing + BorderLeft);

    mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 &&
        x <= pointerX + (int)mPointer->GetWidth() / 2;

    if (mMovingPointer)
    {
        int xx = 0;
    }

    __super::OnLButtonDown(nFlags, point);
}

/** Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context 
 * \return FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

/** Handle the Edit>Set Keyframe menu option */
 void CViewTimeline::OnEditSetkeyframe()
 {
     for (auto actor : *GetPicture())
     {
         actor->SetKeyframe();
     }
 }


 /** Handle the Edit>Delete Keyframe menu option */
 void CViewTimeline::OnEditDeletekeyframe()
 {
     GetPicture()->GetTimeline()->DeleteKeyframe();
     GetPicture()->SetAnimationTime(GetPicture()->GetTimeline()->GetCurrentTime());
 }


 // Doxygen sometimes gets confused by these message 
 // maps, since they look like functions. I've found
 // it helps to move them to the end of the file.
 BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
     ON_WM_CREATE()
     ON_WM_ERASEBKGND()
     ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
     ON_COMMAND(ID_EDIT_DELETEKEYFRAME, &CViewTimeline::OnEditDeletekeyframe)
     ON_WM_LBUTTONDOWN()
     ON_WM_MOUSEMOVE()
 END_MESSAGE_MAP()


