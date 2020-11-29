/**
 * \file Fish.h
 *
 * \author Andrew Decrem
 */

#pragma once
#include "Item.h"
/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class CFish : public CItem
{

    /**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
    CFish(CAquarium* aquarium, const std::wstring& filename);

    void Update(double elapsed);

    /// Default constructor (disabled)
    CFish() = delete;

    /// Copy constructor (disabled)
    CFish(const CFish&) = delete;

private:
    /// Fish speed in the X direction
    double mSpeedX;

    /// Fish speed in the Y direction
    double mSpeedY;

};

