/**
 * \file HeadTop.h
 *
 * \author Andrew Decrem
 *
 * General head top function
 */
#pragma once
#include "ImageDrawable.h"
#include "Drawable.h"

const double RtoD = 57.295779513;

/*

* HeadTop class

*/
class CHeadTop : public CImageDrawable
{
public:
	CHeadTop::CHeadTop(const std::wstring& name, const std::wstring& filename);
	///Virtual destructor
	virtual ~CHeadTop();
	///Default constructor disable
	CHeadTop() = delete;
	///Copy constructor disable
	CHeadTop(const CHeadTop&) = delete;
	///Copy constructor disable
	void operator=(const CHeadTop&) = delete;
	///Transform point
	Gdiplus::Point TransformPoint(Gdiplus::Point p);
	///Virtual draw function
	virtual void Draw(Gdiplus::Graphics* graphics) override;
	///Draw eye
	void DrawEye(Gdiplus::Point p, Gdiplus::Graphics* graphics);
	///Draw eyebrow
	void DrawEyebrow(Gdiplus::Point p1, Gdiplus::Point p2, Gdiplus::Graphics* graphics);
	///Is object movable
	virtual bool IsMovable() override { return true; }
};

