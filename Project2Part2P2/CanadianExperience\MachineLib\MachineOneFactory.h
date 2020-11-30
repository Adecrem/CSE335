/**
 * \file MachineOneFactory.h
 *
 * \author Andrew Decrem
 *
 * Class that represents the first machines factory.
 *
 */
#pragma once
#include "Blower.h"
#include "Shape.h"
#include <memory>
class CMachineOneFactory
{
public:
    ///Default constructor
	CMachineOneFactory();
    ///Destructor
	~CMachineOneFactory();
    
    ///Create working machine
	std::shared_ptr<CBlower> Create();

private:
    /// Create post 
	std::shared_ptr<CShape> CreatePost(int x, int y, int wid, int hit, Gdiplus::Color color); //<Create post, realized I had to make it when I saw an example.
};

