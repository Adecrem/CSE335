/**
 * \file ImageDrawable.h
 *
 * \author Andrew Decrem
 *
 * Drawable image
 */
#pragma once
#include "Drawable.h"
#include <memory>

/*

* Drawable image class

*/
class CImageDrawable : public CDrawable
{
public:
	CImageDrawable(const std::wstring& name, const std::wstring& filename);
	///Virtual destructor
	virtual ~CImageDrawable();
	///Draw function
	void Draw(Gdiplus::Graphics* graphics) override;
	///Hit test function
	bool HitTest(Gdiplus::Point pos) override;
	///Disable the default constructor
	CImageDrawable() = delete;
	///Disable the copy constructor
	CImageDrawable(const CImageDrawable&) = delete;
	///Disable the assignment operator
	void operator=(const CImageDrawable&) = delete;
	///Get the center
	Gdiplus::Point GetCenter() { return mCenter; }
	///Set the center
	void SetCenter(Gdiplus::Point center) { mCenter = center; }
protected:
	/// Image of drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
private:
	///Center
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

