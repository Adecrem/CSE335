/**
 * \file TuitionUp.h
 *
 * \author Team Plessie
 *
 * Stanley object class
 */ 

#pragma once
#include <string>
#include "Item.h"

class CTuitionUp : public CItem
{

public:

    ///  Default constructor (disabled)
    CTuitionUp() = delete;

    ///  Copy constructor (disabled)
    CTuitionUp(const CTuitionUp&) = delete;

    CTuitionUp(CGame* game);

    virtual bool CollisionTest(CItem* item) override;

    ~CTuitionUp();
    
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTuitionUp(this); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mTuitionImage; ///< Background image to use


};
