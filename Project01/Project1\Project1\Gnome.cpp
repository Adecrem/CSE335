/**
 * \file Gnome.cpp
 *
 * \author Team Plessie
 */


#include "pch.h"
#include "Gnome.h"
#include "Vector.h"
#include "ChildView.h"
#include <vector>
#include "Game.h"
#include "ScoreBoard.h"
#include "AddMoneyVisitor.h"
using namespace Gdiplus;
using namespace std;

const wstring GnomeImageName = L"images/gnome.png";             /// Initial load for gnome.png, used for compatibility with CItem Constructor
const wstring GnomeImageNameIdle = L"gnome.png";                    /// Gnome Idle, used for compatibility with SetImage Function
const wstring GnomeRight1ImageName = L"gnome-walk-right-1.png"; /// Gnome right image
const wstring GnomeRight2ImageName = L"gnome-walk-right-2.png"; /// Gnome right image
const wstring GnomeLeft1ImageName = L"gnome-walk-left-1.png"; /// Gnome left image
const wstring GnomeLeft2ImageName = L"gnome-walk-left-2.png"; /// Gnome left image
const wstring GnomeSadImageName = L"images/gnome-sad.png"; /// Gnome sad image

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

/// Walk Cycle Transitions
const double WalkCyclePeak = 12;

const double WalkCycleTransition = WalkCyclePeak / 2.0;

const double WalkCycleReset = 0;

/** Gnome constructor
 * 
 * \param game Game to be played
 */
CGnome::CGnome(CGame* game) : CItem(game, GnomeImageName)
{

}

/**
 * Deconstructor
 */
CGnome::~CGnome()
{
}

/** Draw gnome
 * 
 * \param graphics Gnome image
 */
void CGnome::Draw(Gdiplus::Graphics* graphics)
{

    graphics->DrawImage(mGnomeImage.get(), 0, 0,
        mGnomeImage->GetWidth(), mGnomeImage->GetHeight());
}

/** Gnome update
 * 
 * \param elapsed Time elapsed 
 */
void CGnome::Update(double elapsed)
{
    CItem::Update(elapsed);
    
    if (mIsRight == true)
    {
        if (mWalkRight < WalkCycleTransition)
        {
            SetImage(GnomeLeft1ImageName);
        }
        else if (mWalkRight >= WalkCycleTransition)
        {
            SetImage(GnomeLeft2ImageName);
        }
        mWalkRight++;
        if (mWalkRight == WalkCyclePeak) 
        {
            mWalkRight = WalkCycleReset;
        }

    }
    else if (mIsLeft == true)
    {
        if (mWalkLeft < WalkCycleTransition)
        {
            SetImage(GnomeRight1ImageName);
        }
        else if (mWalkLeft >= WalkCycleTransition)
        {
            SetImage(GnomeRight2ImageName);
        }
        mWalkLeft++;
        if (mWalkLeft == WalkCyclePeak) {
            mWalkLeft = WalkCycleReset;
        }

    }
    else
    {
        SetImage(GnomeImageNameIdle);
    }
    
    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newV(mSpeedX, mSpeedY + Gravity * elapsed);

    // Update position
    CVector p(GetX(), GetY());
    CVector newP = p + newV * elapsed;
    //
    // Try updating the Y location.
    //
    SetLocation(p.X(), newP.Y());
    
    //create object to iterate through
    auto game = GetGame();

    auto collided = GetGame()->CollisionTest(this);
    if (collided != nullptr)
    {
        CAddMoneyVisitor visitor;

        game->Accept(&visitor);

        if (newV.Y() > 0)
        {

            // We are falling, stop at the collision point
            newP.SetY(collided->GetY() - collided->GetHeight() / 2 - GetHeight() / 2 - Epsilon);

        }
        else
        {
     

            // We are rising, stop at the collision point
            newP.SetY(collided->GetY() + collided->GetHeight() / 2 + GetHeight() / 2 + Epsilon);
      

        }

        // If we collide, we cancel any velocity
        // in the Y direction
        newV.SetY(0);

    }

    //
    // Try updating the X location
    //
    SetLocation(newP.X(),newP.Y());

    
    collided = GetGame()->CollisionTest(this);
    if (collided != nullptr)
    {
        if (newV.X() > 0)
        {
            // We are moving to the right, stop at the collision point
            newP.SetX(collided->GetX() - collided->GetWidth() / 2 - GetWidth() / 2 - Epsilon);
        }
        else
        {
            // We are moving to the left, stop at the collision point
            newP.SetX(collided->GetX() + collided->GetWidth() / 2 + GetWidth() / 2 + Epsilon);
        }


        // If we collide, we cancel any velocity
        // in the X direction
        newV.SetX(0);
    }

    // Update the velocity and position
    
    mSpeedX, mSpeedY = newV.X(), newV.Y();
    
    SetLocation(newP.X(), newP.Y());
    
}

/** Key down 
 * 
 * \param nChar Given parameter 
 * \param nRepCnt Given parameter
 * \param nFlags Given parameter
 */
void CGnome::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar)
    {
    case VK_RIGHT:
        // right arrow pressed

        mSpeedX = HorizontalSpeed;
        mIsRight = true;
        break;

    case VK_LEFT:
        // left arrow pressed

        mSpeedX = -HorizontalSpeed;
        mIsLeft = true;
        break;

    case VK_SPACE:
        // space bar pressed
        mSpeedY = JumpSpeed;
        mSpace = true;
        break;
    }
}

/** Keyup function
 * 
 * \param nChar Given parameter
 * \param nRepCnt Given parameter
 * \param nFlags Given parameter
 */
void CGnome::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {
    switch (nChar)
    {
    case VK_RIGHT:
    case VK_LEFT:
        mIsLeft = false;
        mIsRight = false;
        mSpace = false;
        mSpeedX = 0;
        mSpeedY = 0;
        // left or right arrow released
        break;
    }
}


