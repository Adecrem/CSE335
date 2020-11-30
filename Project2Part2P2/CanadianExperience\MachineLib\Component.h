/**
 * \file Component.h
 *
 * \author Andrew Decrem
 *
 * Component class, header file for the component class representing the components.
 */
#pragma once
#include "Polygon.h"
#include <memory>

class CBlower;
class CSink;

class CComponent : public CPolygon
{
public:
	///Default constructor
	CComponent();
	///Virtual deconstructor
	virtual ~CComponent();
	///Copy constructor disable
	CComponent(const CComponent&) = delete;
	///Assignment operator disabled
	void operator=(const CComponent&) = delete;
	///Advance function
	virtual void AdvanceFrame(double delta) {};
	///Update function
	virtual void Update(CSink* sink) {};
	///Virtual draw function
	virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);
	///Set Machine number
	void SetBlowerMachine(CBlower* machine) { mBlowerMachine = machine; }
	///Set the position
	virtual void SetPosition(int x, int y) { mPosition.X = x, mPosition.Y = y; }
	///Get the position
	Gdiplus::Point GetPosition() { return mPosition; }
private:
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0); //< Position

	CBlower* mBlowerMachine = nullptr; //< Blower
};

