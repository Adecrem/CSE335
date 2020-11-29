/**
 * \file PolyDrawable.h
 *
 * \author Andrew Decrem
 *
 * Picture Observer Class
 */
#pragma once
#include "Drawable.h"
#include <vector>
 /**
  * A drawable based on polygon images.
  *
  * This class has a list of points and draws a polygon
  * drawable based on those points.
  */
class CPolyDrawable  : public CDrawable
{
public:
    CPolyDrawable(const std::wstring& name);
    virtual ~CPolyDrawable();
    ///Disable constructor
    CPolyDrawable() = delete;
    ///Disable copy 
    CPolyDrawable(const CPolyDrawable&) = delete;
    ///Disable assignment
    void operator=(const CPolyDrawable&) = delete;
    ///Virtual draw function
    virtual void Draw(Gdiplus::Graphics* graphics) override;
    ///Virtual HitTest 
    virtual bool HitTest(Gdiplus::Point position) override;
    ///Addpoint
    void AddPoint(Gdiplus::Point point);
    ///Get color
    Gdiplus::Color GetColor() { return mColor; }
    ///Set color
    void SetColor(Gdiplus::Color color) { mColor = color; }

private:
    ///mColor and set it to black
    Gdiplus::Color mColor = Gdiplus::Color::Black;
    ///vector of points
    std::vector<Gdiplus::Point> mPoints;
};

