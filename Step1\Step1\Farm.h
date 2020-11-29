/**
 * \file Farm.h
 *
 * \author Charles B. Owen
 *
 * \Edits Andrew Decrem
 * Class that describes a Farm.
 *
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#pragma once
#include <vector>
#include "Animal.h"

 /**
  * Class that describes a farm.
  *
  * Holds a collection of animals that make up the farm
  * inventory.
  */
class CFarm
{
public:
    ~CFarm();
    void AddAnimal(CAnimal *animal);
    void DisplayInventory();
    //function that holds number of defenders
    int numDefenders();

private:
    /// A list with the inventory of all animals on the farm
    std::vector<CAnimal *> mInventory;

};