/**
 * \file PictureFactory.h
 *
 * \author Andrew Decrem
 *
 * Picture Factory class
 */
#pragma once
#include "Picture.h"
#include <memory>
 /**
  *
  * General Picture Factory class
  *
  */
class CPictureFactory
{
public:
    ///Default constructor
	CPictureFactory();
    ///Virtual deconstructor
	virtual ~CPictureFactory();
    ///Shared ptr of create function
	std::shared_ptr<CPicture> Create();
};

