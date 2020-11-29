/**
 * \file Aquarium.h
 *
 * \author Andrew Decrem
 *
 * Class that represents an aquarium.
 */
#pragma once

#include <memory>
#include <vector>

class CItem;

/**
 * Represents an aquarium
 */
class CAquarium
{
public:
    CAquarium();

    void OnDraw(Gdiplus::Graphics* graphics);//ondraw function
    void Add(std::shared_ptr<CItem>);//add function

    std::shared_ptr<CItem> HitTest(int, int);//hit test

    void moveBack(std::shared_ptr<CItem>item);//move back initialization
    
    void position(double, double);//find position

private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;
};