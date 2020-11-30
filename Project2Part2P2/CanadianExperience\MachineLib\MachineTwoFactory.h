/**
 * \file MachineTwoFactory.h
 *
 * \author Andrew Decrem
 *
 * Class that represents the second machines factory.
 *
 */
#pragma once
#include "Blower.h"
#include "Shape.h"
#include <memory>
class CMachineTwoFactory
{
public:
    ///Constructor
	CMachineTwoFactory();

    ///Destructor
	~CMachineTwoFactory();

    ///Create
	std::shared_ptr<CBlower> Create();

    

private:
	std::shared_ptr<CShape> CreatePost(int x, int y, int wid, int hit, Gdiplus::Color color); //< to create a post, realized I had to make it when I looked at the example
};



