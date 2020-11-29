/**
 * \file Game.h
 *
 * \author Team Plessie
 *
 * Game class to control the whole game
 */


#pragma once
#include <memory>
#include <vector>
#include "XmlNode.h"
#include "ScoreBoard.h"
#include "ItemVisitor.h"

class CItem;

class CBackground;

class CGnome;

class CGame
{
public:


    void OnDraw(Gdiplus::Graphics* graphics, int width, int height, std::shared_ptr<CGnome> gnome);

    CGame();

    ~CGame();

    void Add(std::shared_ptr<CItem> item);

    void Update(double elapsed);

    void Load(const std::wstring& filename);

    void Clear();

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

    void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);

    std::shared_ptr<CItem> CollisionTest(CItem* item);

    /** The X location of the item
    * \returns X location in pixels */
    double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    double GetY() const { return mY; }

    double GetWidth() const { return mGnome->GetWidth(); }

    double GetHeight() const { return mGnome->GetHeight(); }

    void Accept(CItemVisitor* visitor);

    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * \param city The city we are iterating over */
        Iter(CGame* city, int pos) : mGame(city), mPos(pos) {}

        /** Test for end of the iterator
         * \returns True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        std::shared_ptr<CItem> operator *() const { return mGame->mItems[mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CGame* mGame;   ///< City we are iterating over
        int mPos;       ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mItems.size()); }


private:

    // Item location in the level
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

    std::vector<std::shared_ptr<CItem> > mItems; ///< items

    std::unique_ptr<Gdiplus::Bitmap> mGnome; ///< actual gnome
    std::shared_ptr<CGnome>  mGnomeImage; ///< gnome image

    std::shared_ptr<CBackground> mItemBackground; ///< item background

    float mScale = 0; ///< scale

    CScoreBoard scoreboard; ///< scoreboard


    

};



