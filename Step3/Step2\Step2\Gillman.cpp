/**
 * \file Gillman.cpp
 *
 * \author Andrew Decrem
 */

#include "pch.h"

#include <memory.h>

#include <string>

#include "Aquarium.h"

#include "Gillman.h"


using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring GillmanNormalImageName = L"images/gillman.png";
const wstring GillmanAfraidImageName = L"images/gillman-afraid.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CGillman::CGillman(CAquarium* aquarium) :
    CItem(aquarium, GillmanNormalImageName)
{
}


