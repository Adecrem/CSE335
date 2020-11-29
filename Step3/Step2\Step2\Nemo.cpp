/**
 * \file Nemo.cpp
 *
 * \author Andrew Decrem
 */

#include "pch.h"

#include <string>

#include "Nemo.h"

using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring NemoImageName = L"images/nemo.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CNemo::CNemo(CAquarium* aquarium) :
    CItem(aquarium, NemoImageName)
{
}



