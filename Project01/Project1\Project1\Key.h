/**
 * \file Key.h
 *
 * \author Team Plessie
 *
 * Key special item implementation 
 */

#pragma once
#include "Item.h"


class CKey : public CItem
{

public:

    ///  Default constructor (disabled)
    CKey() = delete;

    ///  Copy constructor (disabled)
    CKey(const CKey&) = delete;

    CKey(CGame* game);

    ~CKey();

	virtual void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

    void OnDraw(Gdiplus::Graphics* graphics);

    //bool CollisionTest(CItem* item);

    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    //wstring KeyImageName = L"images/key.png";

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitKey(this); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mKeyImage; ///< Background image to use

};

