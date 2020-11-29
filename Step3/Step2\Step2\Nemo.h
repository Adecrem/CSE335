/**
 * \file Nemo.h
 *
 * \author Andrew Decrem
 */

#pragma once

#include <memory>

#include "Item.h"

/**
 * Implements a Beta fish
 */
class CNemo :
    public CItem
{
public:
    CNemo(CAquarium* aquarium);

    /// Default constructor (disabled)
    CNemo() = delete;

    /// Copy constructor (disabled)
    CNemo(const CNemo&) = delete;


private:
    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

