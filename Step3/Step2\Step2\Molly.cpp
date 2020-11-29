/**
 * \file Molly.cpp
 *
 * \author Andrew Decrem
 */

#include "pch.h"
#include <string>
#include "Molly.h"

using namespace Gdiplus;
using namespace std;

const wstring MollyImageName = L"images/molly.png";//image of molly fish


/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CMolly::CMolly(CAquarium* aquarium) :
    CItem(aquarium, MollyImageName)
{
}