/**
 * \file DecorCastle.cpp
 *
 * \author Andrew Decrem
 */


#include "pch.h"
#include <string>
#include "DecorCastle.h"

using namespace std;
using namespace Gdiplus;


const wstring CastleImageName = L"images/castle.png";

CDecorCastle::CDecorCastle(CAquarium* aquarium) : 
    CItem(aquarium, CastleImageName)
{
}