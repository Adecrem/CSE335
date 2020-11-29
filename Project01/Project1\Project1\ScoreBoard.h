/**
 * \file ScoreBoard.h
 *
 * \author team Plessie
 *
 * Scoreboard header file 
 */


#pragma once
#include "Level.h"

class CScoreBoard : public CLevel
{

public:


    void timer(double time, Gdiplus::Graphics* graphics, int scrollX);

    void Update(double elapsed);

    int bank() const {
        return balance;
    }


	void score();

	void displayscore();

    void Draw(Gdiplus::Graphics* graphics, int scrollX);

private:
    double mDuration = 0; ///< time
    int balance = 0; ///< balance of bank

};

