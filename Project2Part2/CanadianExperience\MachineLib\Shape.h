/**
 * \file Shape.h
 *
 * \author Andrew Decrem
 *
 * Class that the shape in the machine.
 *
 */
#pragma once
#include "Component.h"
#include "Sink.h"
class CShape : public CComponent
{
public:
	///Constructor
	CShape();

	///Virtual destructor
	virtual ~CShape();

	///Copy constructor disabled
	CShape(const CShape&) = delete;

	///Assignment operator disabled
	void operator=(const CShape&) = delete;

	///Getter for sink
	CSink* GetSink() { return &mSink; }

	///Update sink
	virtual void Update(CSink* sink);

private:

	CSink mSink; //< The sink
};

