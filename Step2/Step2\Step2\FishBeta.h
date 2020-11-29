/**
 * \file FishBeta.h
 *
 * \author Charles B. Owen
 *
 * Class the implements a Beta fish
 */

#pragma once

#include <memory>

#include "Item.h"

 /**
  * Implements a Beta fish
  */
class CFishBeta :
    public CItem
{
public:
    CFishBeta(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta &) = delete;

    bool HitTest(int, int);

    virtual void Draw(Gdiplus::Graphics* graphics) override;

private:
    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

