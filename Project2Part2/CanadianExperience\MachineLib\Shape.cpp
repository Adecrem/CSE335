/**
 * \file Shape.cpp
 *
 * \author Andrew Decrem
 *
 * Shape class
 *
 */
#include "pch.h"
#include "Shape.h"
#include "Sink.h"



/**
 * Constructor
 */
CShape::CShape()
{
	mSink.SetComponent(this);
}


/**
 * Destructor
 */
CShape::~CShape()
{

}



/**
 * Update the sink
 * \param sink 
 */
void CShape::Update(CSink* sink)
{
    auto sinkRoto = mSink.GetRotation();
	if (sink = &mSink)
	{
		SetRotation(sinkRoto);
	}
}