/**
 * \file Item.cpp
 *
 * \author Andrew Decrem
 */

#include "pch.h"
#include "Item.h"
#include "Gillman.h"
#include "Aquarium.h"


 /** Constructor
 * \param aquarium The aquarium this item is a member of
 */
CItem::CItem(CAquarium* aquarium) : mAquarium(aquarium)
{
}


/**
 * Destructor
 */
CItem::~CItem()
{
}

/*
* Afraid function will return draw and decide whether to switch
*/
void CItem::afraid(double x, double y) {
    double item1 = mX;
    double item2 = mY;
    //initializing items

    // Distance in the X and Y directions
    double dx = item1 - x;//setting x and y
    double dy = item2 - y;

    double distance = sqrt(dx * dx + dy * dy);
    if (distance <= 300) {
        CGillman::Draw;//draw if in range
    }
}