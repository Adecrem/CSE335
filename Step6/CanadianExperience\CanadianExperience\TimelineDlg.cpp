// TimelineDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "TimelineDlg.h"
#include "afxdialogex.h"
#include "Timeline.h"


// CTimelineDlg dialog

IMPLEMENT_DYNAMIC(CTimelineDlg, CDialogEx)

CTimelineDlg::CTimelineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIMELINEDLG, pParent)
	, mNumFrames(0)
	, mFrameRate(0)
{

}
/** Destructor */
CTimelineDlg::~CTimelineDlg()
{
}



BEGIN_MESSAGE_MAP(CTimelineDlg, CDialogEx)
END_MESSAGE_MAP()


// CTimelineDlg message handlers

void CTimelineDlg::SetTimeline(CTimeline* timeline)

{
	mTimeline = timeline;
	mNumFrames = mTimeline->GetNumFrames();
	mFrameRate = mTimeline->GetFrameRate();
}


void CTimelineDlg::Take()
{
	mTimeline-> SetNumFrames(mNumFrames);
	mTimeline->SetFrameRate(mFrameRate);
}