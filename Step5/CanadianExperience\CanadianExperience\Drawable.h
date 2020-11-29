/**
 * \file Drawable.h
 *
 * \author Andrew Decrem
 *
 * Drawable class
 */
#pragma once
#include <memory>
#include <string>
#include <vector>
 /**
  * Abstract base class for drawable elements of our picture.
  *
  * A drawable is one part of an actor. Drawable parts can be moved
  * independently.
  */
class CActor;

class CDrawable
{
public:
    ///virtual  deconstructor
    virtual ~CDrawable();
    /// Disable default constructor
    CDrawable() = delete;
    /// Disable copy constructor
    CDrawable(const CDrawable&) = delete;
    /// Disable assignment operator
    void operator=(const CDrawable&) = delete;



    void SetActor(CActor* actor);
    ///Draw graphics
    virtual void Draw(Gdiplus::Graphics* graphics) = 0;

    ///Where to place and rotate
    void Place(Gdiplus::Point offset, double rotate);

    ///Add child function
    void AddChild(std::shared_ptr<CDrawable> child);
    ///Hit test to see if hit
    virtual bool HitTest(Gdiplus::Point position) = 0;
    ///Is the object movable
    virtual bool IsMovable() { return false; }
    ///Move the object
    void Move(Gdiplus::Point delta);
    ///Set the position
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

    ///Get the position
    Gdiplus::Point GetPosition() const { return mPosition; }

    ///Set the rotation angle
    void SetRotation(double r) { mRotation = r; }

    ///Get the rotation angle
    double GetRotation() const { return mRotation; };

    ///Get the drawable name
    std::wstring GetName() const { return mName; }
    ///Set the parent
    void SetParent(CDrawable* parent) { mParent = parent; }
    ///Get the parent
    CDrawable* GetParent() const { return mParent; }

protected:
    ///Drawable name
    CDrawable(const std::wstring& name);
    ///Point of rotation
    Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);
    ///Placed position
    Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);
    ///Placed position
    double mPlacedR = 0;

private:
    ///Name
    std::wstring mName;
    ///Position
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
    double mRotation = 0;
    ///Actor
    CActor* mActor = nullptr;
    ///Children drawing
    std::vector<std::shared_ptr<CDrawable>> mChildren;
    ///Parent drawing
    CDrawable* mParent = nullptr;
};

