/**
 * \file Gillman.h
 *
 * \author Andrew Decrem
 */

#pragma once

#include <memory>

#include "Item.h"

/**
 * Implements a Beta fish
 */
class CGillman :
    public CItem
{
public:
    CGillman(CAquarium* aquarium);

    /// Default constructor (disabled)
    CGillman() = delete;

    /// Copy constructor (disabled)
    CGillman(const CGillman&) = delete;


private:
    std::unique_ptr<Gdiplus::Bitmap>mGillmanNormal;
    std::unique_ptr<Gdiplus::Bitmap>mGillmanAfraid;
    //initializing Gillmans
};


