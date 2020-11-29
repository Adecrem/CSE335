/**
* \file Cow.h
*
* \author Charles B. Owen
* \edited by Andrew Decrem
*
* Class that describes a cow.
*/

#pragma once

#include <string>
#include "Animal.h"

/**
 * Describes a single cow.
 */
class CCow : public CAnimal
{
public:

	/// The types of cow we can have on our farm
	enum Type { Bull, BeefCow, MilkCow };

	void ObtainCowInformation();
	void DisplayAnimal();
	//function to find if it is a defender
	int isDefender();

private:
	/// The cow's name
	std::string mName;

	/// The type of code: Bull, BeefCow, or MilkCow
	Type mType = MilkCow;

	/// The milk production for a cow in gallons per day
	double mMilkProduction = 0;
};


