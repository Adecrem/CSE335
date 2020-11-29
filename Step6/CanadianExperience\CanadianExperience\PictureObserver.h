/**
 * \file Picture.h
 *
 * \author Andrew Decrem
 *
 * Picture Observer Class
 */
#pragma once
#include <memory>
class CPicture;
/**
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
class CPictureObserver
{
public:
    void SetPicture(std::shared_ptr<CPicture> picture);
    /// Virtual destructor
    virtual ~CPictureObserver();
    /// Copy Constructor (Disabled)
    CPictureObserver(const CPictureObserver&) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const CPictureObserver&) = delete;

    /// This function is called to update any observers
    virtual void UpdateObserver() = 0;

    std::shared_ptr<CPicture>GetPicture() { return mPicture; }
private:
    /// Picture we are observing
    std::shared_ptr<CPicture> mPicture;
protected:
    CPictureObserver();
};