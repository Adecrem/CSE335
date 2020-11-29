/**
 * \file Step1.cpp
 *
 * \author Andrew Decrem
 */

#include <iostream>
#include "Animal.h"
#include "Farm.h"
#include "Cow.h"
#include "leak.h"
#include "Chicken.h"
#include "Ant.h"

using namespace std;

/**
 * Main entry point.
 *
 * This is where the program starts.
 * \return 0
 */
int main()
{
	// Support memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "Instantiating Farm" << endl;
	CFarm farm;

	// This loops continuously until we are done
	bool done = false;
	while (!done)
	{
		// Output user instructions
		cout << endl;
		cout << "Farm management" << endl;
		cout << "1 - Add cow" << endl;
		cout << "2 - Add Chicken" << endl;
		cout << "3 - Add Ant" << endl;
		cout << "4 - Number of defenders" << endl;
		cout << "9 - List inventory" << endl;
		cout << "99 - Exit" << endl;
		cout << "Select Option: ";

		// Get option from the user
		int count = 0;
		int option;
		cin >> option;

		// Handle invalid  input
		if (!cin)
		{
			option = 1000;
			cin.clear();
			cin.ignore();  // Discard bad input
		}

		// Handle the possible user options
		switch (option)
		{
		case 1:
		{
			//adds cow
			cout << "Adding cow" << endl;
			CCow* cow = new CCow();
			cow->ObtainCowInformation();
			farm.AddAnimal(cow);
		}
		break;

		case 2:
		{
			//adds chicken
			cout << "Adding chicken" << endl;
			CChicken* chicken = new CChicken();
			chicken->ObtainChickenInformation();
			farm.AddAnimal(chicken);
		}
		break;

		case 3:
		{
			//adds ant
			cout << "Adding ant" << endl;
			CAnt* ant = new CAnt();
			ant->ObtainAntInformation();
			farm.AddAnimal(ant);
		}
		break;

		case 4:

		{
			//returns how many defenders there are
			cout << "There are " << farm.numDefenders() << " defenders" << endl;
		}
		break;

		case 9:
			//displays animals in farm
			farm.DisplayInventory();
			break;

		case 99:
			//closes program
			done = true;
			break;

		default:
			cout << "Invalid option" << endl;
			break;
		}
	}

	return 0;
}