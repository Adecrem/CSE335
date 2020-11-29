/**
 * \file Door.h
 *
 * \author Tean Plessie
 *
 * Door header file initializes door 
 */


#pragma once
#include <string>
#include "Item.h"
class CDoor : public CItem
{

public:


    ///  Default constructor (disabled)
    CDoor() = delete;

    ///  Copy constructor (disabled)
    CDoor(const CDoor&) = delete;

    CDoor(CGame* game);

    ~CDoor();

	virtual void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual bool CollisionTest(CItem* item);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDoor(this); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mDoorImage; ///< Background image to use
};