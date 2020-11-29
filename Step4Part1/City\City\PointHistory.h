/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);

protected:
    /// Data is stored in alternating locations in 
    /// the multiple hot potato lists.
    std::vector<Gdiplus::Point> mPotatoLists[NumLists];

    /// The current list we are adding points to. Each time
    /// we add a point, we will add it to this list, then 
    /// change mCurrentList to change to the next list.
    int mCurrentList = 0;
};

