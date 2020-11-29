/**
 * \file Villain.h
 *
 * \author Team Plessie
 *
 * Villian object class
 */


#pragma once
#include <string>
#include "Item.h"
#include <memory>

using namespace std;

class CVillain : public CItem
{

public:

    ///  Default constructor (disabled)
    CVillain(CGame* game);

    ///  Default constructor (disabled)
    CVillain() = delete;

    ///  Copy constructor (disabled)
    CVillain(const CVillain&) = delete;

    ~CVillain();

    void OnDraw(Gdiplus::Graphics* graphics);

    virtual void Draw(Gdiplus::Graphics* graphics, int scrollX) override;

    void Update(double elapsed);
    
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitVillain(this); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mVillainImage; ///< Background image to use
    bool mIsUp = true; ///< is the villian up
    bool mIsDown = false; ///< is the villian down

    double mYOrigin; ///< origin
};
