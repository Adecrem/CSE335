/**
 * \file MachineOneFactory.h
 *
 * \author Andrew Decrem
 *
 * Class that represents the sink in the machine.
 *
 */
#pragma once
class CSource;
class CComponent;

class CSink
{
public:
	///Constructor
	CSink();
	~CSink();
	///Disable copy constructor
	CSink(const CSink&) = delete;
	///Disable assignment operator
	void operator=(const CSink&) = delete;
	///Setter for source
	void SetSource(CSource* source) { mSource = source; }
	///Setter for component
	void SetComponent(CComponent* component) { mComponent = component; }
	///Getter for component
	CComponent* GetComponent() { return mComponent; }
	///Set rotation
	void SetRotation(double RPM);
	///Getter for rotation
	double GetRotation() { return mRPM; }
private:
	double mRPM; //< The RPM
	CSource* mSource = nullptr; //< The source
	CComponent* mComponent = nullptr; //< The component

};

