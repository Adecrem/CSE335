/**
 * \file Animal.h
 *
 * \Andrew Decrem
 */
#pragma once
#include <iostream>
class CAnimal
{
public:
	virtual ~CAnimal();
	/** Display an animal. */
	virtual void DisplayAnimal() {}
	//virtual function to check if it is a defender
	virtual int isDefender() 
	{
		return 0;//default is returning 0
	}

};


//https://www.geeksforgeeks.org/virtual-function-cpp/

//Above link used for further understanding of virtual functions

