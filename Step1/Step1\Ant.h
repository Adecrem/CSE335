/**
* \File Ant.h
*
*
*\Author: Andrew Decrem
*/

#pragma once
#include <string>
#include "Animal.h"


class CAnt : public CAnimal
{
public:
	//different types of ants
	enum Type { WorkerAnt, SoldierAnt, Drone, Queen};
	//obtain information
	void ObtainAntInformation();
	//display
	void DisplayAnimal();
	//defender check
	int isDefender();

private:
	std::string mCode;
	Type mType;
};

