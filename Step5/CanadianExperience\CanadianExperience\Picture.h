/**
 * \file Picture.h
 *
 * \author Andrew Decrem
 *
 * Picture class
 */
#pragma once

class CPictureObserver;
#include <memory>
#include <vector>
#include "Actor.h"
/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
class CPicture
{
public:
    CPicture();
    virtual ~CPicture();

    /// Copy Constructor (Disabled)
    CPicture(const CPicture&) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const CPicture&) = delete;

    /** The picture size
     * \returns Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** The picture size
     * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver* observer);
    void RemoveObserver(CPictureObserver* observer);
    void UpdateObservers();
    void Draw(Gdiplus::Graphics* graphics);
    void AddActor(std::shared_ptr<CActor>actor);

    /** Iterate over actors in the picture */
    //I tried to just write based on the test provided, this seemed to work, but I'm not fully sure.
    //https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterators.html
    //^^Used that for help
    class Iter
    {
    public:
        /**Constructor
        *\param picture Iterated picture
        *\param pos The position
        */
        Iter(CPicture* picture, int pos) : mPicture(picture), mPos(pos) {}
        /**Test iterator
        * \param other Second iterator
        * \return bool Whether they equal eachother
        */
        bool operator==(const Iter& iter2) const
        {
            return mPos == iter2.mPos;
        }



        /**Test ending of iterator
        * \param other Second iterator
        * \return bool Whether they equal eachother
        */
        bool operator!=(const Iter& iter2) const
        {
            return mPos != iter2.mPos;
        }

        /** Return value at position*/
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

        /** Incrementing iterator
        * \return reference of operator
        */
        const Iter& operator ++()
        {
            mPos++;
            return *this;
        }
    private:
        /// Picture to be iterated
        CPicture* mPicture;
        ///position
        int mPos;
    };
    ///Iterator at beginning
    Iter begin() { return Iter(this, 0); }
    ///Iterator at end
    Iter end() { return Iter(this, mActors.size()); }
private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);
    /// The observers of this picture
    std::vector<CPictureObserver *> mObservers;

    ///Vector of actors
    std::vector<std::shared_ptr<CActor>> mActors;
};

