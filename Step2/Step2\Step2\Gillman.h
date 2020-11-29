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

    //hit test to see if hit
    bool HitTest(int, int);

    //draw function that can override
    virtual void Draw(Gdiplus::Graphics* graphics) override;


private:
    std::unique_ptr<Gdiplus::Bitmap>mGillmanNormal;
    std::unique_ptr<Gdiplus::Bitmap>mGillmanAfraid;
    //initializing Gillmans
};


