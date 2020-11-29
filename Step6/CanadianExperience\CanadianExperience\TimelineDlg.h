/**
 * \file TimelineDlg.h
 *
 * \author Andrew Decrem
 *
 * Timeline Dialog
 */
#pragma once
class CTimeline;


// CTimelineDlg dialog

class CTimelineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	CTimelineDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTimelineDlg();
	void SetTimeline(CTimeline* timeline);
	void Take();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int mNumFrames;
	CTimeline* mTimeline = nullptr;
	int mFrameRate;
};
