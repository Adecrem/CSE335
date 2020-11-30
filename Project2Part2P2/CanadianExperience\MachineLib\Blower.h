/**
 * \file Blower.h
 *
 * \author Andrew Decrem
 *
 * Blower class
 *
 * 
 */
#pragma once
#include <memory>
#include <vector>

class CTempMachine;
class CComponent;
class CMotor;

class CBlower
{
public:
	///Constructor
	CBlower(int num) : mNum(num) {};
	///Default disabled
	CBlower() = delete;
	///Copy constructor disabled
	CBlower(const CBlower&) = delete;
	///Assignment operator disabled
	void operator =(const CBlower&) = delete;
	///Set the temp machine
	void SetTempMachine(CTempMachine* machine) { mTempMachine = machine; }
	///Set the time
	void SetTime(double time);
	///Advance function suggested on the website
	void AdvanceFrame(double delta);
	///Draw machine with graphics and coordinates
	void DrawMachine(Gdiplus::Graphics* graphics, int x, int y);
	///Set machine number
	void SetMichNumber(int num) { mNum = num; }
	///Add component
	void AddComponent(std::shared_ptr<CComponent> component);
	///Add the motor
	void AddMotor(std::shared_ptr<CMotor> motor) { mMotors.push_back(motor); }
private:

	int mNum; //< Machine number
	CTempMachine* mTempMachine = nullptr; //< Pointer to temp machine
	std::vector<std::shared_ptr<CComponent>> mComponents; //< Vector of components
	std::vector<std::shared_ptr<CMotor>> mMotors; //<Vector of motors.

};

