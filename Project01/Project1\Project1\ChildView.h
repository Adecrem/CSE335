/**
 * \file ChildView.h
 *
 * \author Team Plessie
 *
 * Childview header file initializes everything
 */

#pragma once
#include "Game.h"
#include "Gnome.h"
#include "Villain.h"
// CChildView window

class CChildView : public CWnd
{
	// Construction
public:
	CChildView();

	// Attributes
public:

	// Operations
public:

	// Overrides
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// Implementation
public:
	virtual ~CChildView();

	std::shared_ptr<CGnome> GetGnome() { return gnome;  }

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()

private:
	CGame mGame;

	int mCurrentLevel = 1;

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime = 0;    ///< Last time we read the timer
	double mTimeFreq = 0;       ///< Rate the timer updates

	std::shared_ptr<CGnome> gnome = make_shared<CGnome>(&mGame);
public:
	afx_msg void OnLevelsLevel0();
	std::shared_ptr<CItem> mGrabbedItem;
	double mStartupMessage = 0;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLevelsLevel1();
	afx_msg void OnLevelsLevel2();
	afx_msg void OnLevelsLevel3();
};

