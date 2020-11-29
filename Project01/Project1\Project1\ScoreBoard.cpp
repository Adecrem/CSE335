/**
 * \file ScoreBoard.cpp
 *
 * \author Team Plessie
 */


#include "pch.h"
#include "ScoreBoard.h"
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <sstream>
#include "ChildView.h"
#include "Gnome.h"
#include "Vector.h"
#include <vector>
#include "Game.h"

using namespace Gdiplus;
using namespace std;



/** Incramenting timer
 * 
 * \param time Time passed
 * \param graphics Timer text
 * \param scrollX Scroll offset so it stays in place
 */
void CScoreBoard::timer(double time, Gdiplus::Graphics* graphics, int scrollX) 
{
    int minutes = (int)time / 60;
    int seconds = (int)time % 60;

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 72);
    SolidBrush color(Color::DarkTurquoise);

    wstringstream final;
    final << minutes << L":" << setw(2) << setfill(L'0') << seconds << ends;

    graphics->DrawString(final.str().c_str(),  // String to draw
        -1,         // String length, -1 means it figures it out on its own
        &font,      // The font to use
        PointF(scrollX, 20.0f),
        &color);    // The brush to draw the text with

}

/** Update to get elapsed time
 * 
 * \param elapsed Time that has elapsed
 */
void CScoreBoard::Update(double elapsed) {
    mDuration += elapsed;
}


/**
 * Implementing score
 */
void CScoreBoard::score()
{
    /*Items = 
    for (item : Items)
    auto collided = GetGame()->CollisionTest(this);
    if (collided != nullptr)
    {
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
    }*/
}
//useless comment


/**
 * Display scoreboard
 */
void CScoreBoard::displayscore()
{


}

/** Draw for Scoreboard
 * 
 * \param graphics Timer text
 * \param scrollX Scroll offest
 */
void CScoreBoard::Draw(Gdiplus::Graphics* graphics, int scrollX) {
    timer(mDuration, graphics, scrollX);
}