/**
 * \file ChildView.cpp
 *
 * \author Team Plessie
 */

#include "pch.h"
#include "framework.h"
#include "Project1.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"
#include "XmlNode.h"
#include "Money.h"
#include "Background.h"
#include "Key.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;

/// Frame duration in milliseconds
const int FrameDuration = 30;

const int StartMsg = 2;


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_LEVELS_LEVEL0, &CChildView::OnLevelsLevel0)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(ID_LEVELS_LEVEL1, &CChildView::OnLevelsLevel1)
	ON_COMMAND(ID_LEVELS_LEVEL2, &CChildView::OnLevelsLevel2)
	ON_COMMAND(ID_LEVELS_LEVEL3, &CChildView::OnLevelsLevel3)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height(), gnome);

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);
		/*
		auto background = make_shared<CBackground>(&mGame);
		background->SetLocation(background->GetWidth() / 2, background->GetHeight() / 2);
		mGame.Add(background);
		Invalidate();
		
		gnome->SetLocation(500, 800);
		mGame.Add(gnome);
		Invalidate();
		
		auto villain = make_shared<CVillain>(&mGame);
		villain->SetLocation(500, 600);
		mGame.Add(villain);
		Invalidate();
		
		auto money = make_shared<CMoney>(&mGame);
		money->SetLocation(800, 800);
		mGame.Add(money);
		Invalidate();
		
		auto key = make_shared<CKey>(&mGame);
		key->SetLocation(0, 0);
		mGame.Add(key);
		Invalidate();
		*/

		/*
		 * Initialize the elapsed time system
		 */
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}
	// Do not call CWnd::OnPaint() for painting messages

	/*
	 * Compute the elapsed time since the last draw
	 */
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	if (mCurrentLevel == 0 && mStartupMessage <= StartMsg)
	{
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 72);
		SolidBrush blue(Color(0, 0, 64));
		graphics.DrawString(L"Level 0 Begin",  // String to draw
			-1,         // String length, -1 means it figures it out on its own
			&font,      // The font to use
			PointF((Gdiplus::REAL)rect.Width() / 4, (Gdiplus::REAL)rect.Height() / 4),   // Where to draw (top left corner)
			&blue);    // The brush to draw the text with
	}
	else if (mCurrentLevel == 1 && mStartupMessage <= StartMsg)
	{
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 72);
		SolidBrush blue(Color(0, 0, 64));
		graphics.DrawString(L"Level 1 Begin",  // String to draw
			-1,         // String length, -1 means it figures it out on its own
			&font,      // The font to use
			PointF((Gdiplus::REAL)rect.Width() / 4, (Gdiplus::REAL)rect.Height() / 4),   // Where to draw (top left corner)
			&blue);    // The brush to draw the text with
	}
	else if (mCurrentLevel == 2 && mStartupMessage <= StartMsg)
	{
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 72);
		SolidBrush blue(Color(0, 0, 64));
		graphics.DrawString(L"Level 2 Begin",  // String to draw
			-1,         // String length, -1 means it figures it out on its own
			&font,      // The font to use
			PointF((Gdiplus::REAL)rect.Width() / 4, (Gdiplus::REAL)rect.Height() / 4),   // Where to draw (top left corner)
			&blue);    // The brush to draw the text with
	}
	else if (mCurrentLevel == 3 && mStartupMessage <= StartMsg)
	{
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 72);
		SolidBrush blue(Color(0, 0, 64));
		graphics.DrawString(L"Level 3 Begin",  // String to draw
			-1,         // String length, -1 means it figures it out on its own
			&font,      // The font to use
			PointF((Gdiplus::REAL)rect.Width() / 4, (Gdiplus::REAL)rect.Height() / 4),   // Where to draw (top left corner)
			&blue);    // The brush to draw the text with
	}
	else
	{
		mGame.Update(elapsed);
	}
	mStartupMessage += elapsed;
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	mGame.OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	mGame.OnKeyUp(nChar, nRepCnt, nFlags);
}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CWnd::OnTimer(nIDEvent);

}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return FALSE;
}


void CChildView::OnLevelsLevel0()
{
	mCurrentLevel = 0;

	mGame.Load(L"levels/level0.xml");
	gnome->SetLocation(500, 800);
	Invalidate();
}


void CChildView::OnLevelsLevel1()
{
	mCurrentLevel = 1;
	mStartupMessage = 1;
	
	mGame.Load(L"levels/level1.xml");
	gnome->SetLocation(500, 800);
	mGame.Add(gnome);
	Invalidate();
}


void CChildView::OnLevelsLevel2()
{
	mCurrentLevel = 2;
	mStartupMessage = 1;

	mGame.Load(L"levels/level2.xml");
	gnome->SetLocation(500, 800);
	mGame.Add(gnome);
	Invalidate();
}


void CChildView::OnLevelsLevel3()
{
	mCurrentLevel = 3;
	mStartupMessage = 1;

	mGame.Load(L"levels/level3.xml");
	gnome->SetLocation(500, 800);
	mGame.Add(gnome);
	Invalidate();
}

