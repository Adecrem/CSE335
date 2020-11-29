/**
 * \file Chicken.h
 *
 * \author Andrew Decrem
 *
 * Declaration of the CChicken class.
 */

#pragma once

#include <string>
#include "Animal.h"

 /** Class that describes a chicken.
 */
class CChicken : public CAnimal
{
public:
    //obtain chicken information
    void ObtainChickenInformation();
    //display information
    void DisplayAnimal();

private:
    //! The chicken's ID
    std::string mId;
};

