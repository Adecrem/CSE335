/**
 * \file Ant.cpp
 *
 * \Andrew Decrem
 */

#include "Ant.h"
#include <iostream>
#include <cctype>
#include "Animal.h"

using namespace std;

//obtain the information
void CAnt::ObtainAntInformation() {
	cout << endl;
	cout << "Input information about the ant" << endl;

	//Obtain the code
	cout << "Code: ";
	cin >> mCode;
	//if code is not satisfactory
	if (mCode.size() != 3 or isupper(mCode[0]) == false or isupper(mCode[1]) == false or isupper(mCode[2]) == false) { //code must be all caps 3 letters
		cout << "Please enter a valid code." << endl;
		cin.clear();
		cin.ignore();
		ObtainAntInformation();
	}

	//give user option
	bool valid = false;
	while (!valid) {
		cout << "1: Worker Ant - Specialized to do work." << endl;
		cout << "2: Soldier Ant - Specialized to do battle." << endl;
		cout << "3: Drone - Fertile male ant." << endl;
		cout << "4: Queen - Fertile female ant." << endl;
		cout << "Enter selection and return: ";
		int option;
		cin >> option;
		if (!cin) {
			cin.clear();
			cin.ignore();
			continue;
		}
		switch (option)
		{
			//different types of ants have different cases
		case 1:
			mType = WorkerAnt;
			valid = true;
			break;
		case 2:
			mType = SoldierAnt;
			valid = true;
			break;
		case 3:
			mType = Drone;
			valid = true;
			break;
		case 4:
			mType = Queen;
			valid = true;
			break;
		}

	}
}
	//display animal
	void CAnt::DisplayAnimal()
	{
		//different types of ants will output different descriptions
		cout << "Ant " << mCode << " is a ";
		switch (mType)
		{
		case WorkerAnt:
			cout << "Worker Ant" << endl;
			break;
		case SoldierAnt:
			cout << "Soldier Ant" << endl;
			break;
		case Drone:
			cout << "Drone" << endl;
			break;
		case Queen:
			cout << "Queen" << endl;
			break;
		}
	}
	//check if ant is a defender
	int CAnt::isDefender() {
		if (mType == SoldierAnt) {
			return 1;//return 1 if it is a defender
		}
		else {
			return 0;//0 if not
		}
	}

