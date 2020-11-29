/**
 * \file Platform.h
 *
 * \author Team Plessie
 *
 * Platform object header file
 */



#pragma once
#include <string>
#include "Item.h"

class CPlatform : public CItem
{

public:

    ///  Default constructor (disabled)
    CPlatform() = delete;

    ///  Copy constructor (disabled)
    CPlatform(const CPlatform&) = delete;

    CPlatform(CGame* game);

    ~CPlatform();

    double GetPlatformHeight() const { return mHeight; }

    double GetPlatformWidth() const { return mWidth; }

	virtual void Draw(Gdiplus::Graphics* graphics, int scrollX) override;
    
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPlatform(this); }

private:

    double mWidth = 0;   ///< Width for Item
    double mHeight = 0;   ///< Height for Item

    std::unique_ptr<Gdiplus::Bitmap> mPlatformImage; ///< Background image to use
};

