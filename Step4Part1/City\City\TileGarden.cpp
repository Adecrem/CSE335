/**
* \file TileGarden.cpp
*
* \author Andrew Decrem
*
*  Represents the garden tile
*/


#include "pch.h"
#include "TileGarden.h"


/**
 * Called before the image is drawn
 * \param elapsed Time since last draw
 */
void CTileGarden::Update(double elapsed)
{
    CTile::Update(elapsed);

    int mSincePruning = 0;

    mSincePruning += elapsed;
    //if seconds are less than 2
    if (mSincePruning < 2){
        PruningStates mPruningState = PruningStates::Overgrown1;
        SetImage(L"images/Garden1.png");

    }//if seconds are between 2 and 4
    else if (mSincePruning >= 2 && mSincePruning <= 4) {
        PruningStates mPruningState = PruningStates::Overgrown2;
        SetImage(L"images/garden2.png");

    }
    //if seconds are between 4 and 7
    else if (mSincePruning >= 4 && mSincePruning <= 7) {
        PruningStates mPruningState = PruningStates::Overgrown3;
        SetImage(L"images/garden3.png");
    }//if seconds are 10 or above
    else if (mSincePruning >= 10) {
        PruningStates mPruningState = PruningStates::Overgrown4;
        SetImage(L"images/garden4.png");
    }
}