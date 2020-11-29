/**
 * \file Farm.cpp
 *
 * \Andrew Decrem
 */

#include "Farm.h"
#include "leak.h"
#include "Animal.h"
#include "Chicken.h"
#include "Ant.h"
#include "Cow.h"


 /**
  * Destructor.
  */
CFarm::~CFarm()
{
	// Iterate over all of the animals, destroying 
	// each one.
	for (auto animal : mInventory)
	{
		delete animal;
	}

	// And clear the list
	mInventory.clear();
}


/** Add an animal to the farm inventory.
*
* \param cow A cow to add to the inventory
*/
void CFarm::AddAnimal(CAnimal *animal)
{
	mInventory.push_back(animal);
}


/**
* Display the farm inventory.
*/
void CFarm::DisplayInventory()
{
	for (auto animal : mInventory)
	{
		animal->DisplayAnimal();
	}
}
/**
*tallys the number of defenders
*/
int CFarm::numDefenders() {
	int defenders = 0;
	for (auto animal : mInventory) {
		if (animal->isDefender() == 1) {
			defenders++;
		}
	}
	return defenders;
}

//returned 1 in tests so I could sort which one's are defenders



