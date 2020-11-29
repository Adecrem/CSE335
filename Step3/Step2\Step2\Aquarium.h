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
#include <string>
#include "XmlNode.h"

class CItem;

/**
 * Represents an aquarium
 */
class CAquarium
{
public:
    CAquarium();

    ~CAquarium();

    void OnDraw(Gdiplus::Graphics* graphics);//ondraw function

    void Add(std::shared_ptr<CItem>);//add function

    std::shared_ptr<CItem> HitTest(int, int);//hit test

    void moveBack(std::shared_ptr<CItem>item);//move back initialization

    void MoveToFront(std::shared_ptr<CItem>item);
    
    /// Get the width of the aquarium
/// \returns Aquarium width
    int GetWidth() const { return mBackground->GetWidth(); }

    /// Get the height of the aquarium
    /// \returns Aquarium height
    int GetHeight() const { return mBackground->GetHeight(); }

    void Clear();
    //save
    void CAquarium::Save(const std::wstring& filename);
    //load
    void CAquarium::Load(const std::wstring& filename);
    //update item based on time elapsed
    void Update(double elapsed);
private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
};