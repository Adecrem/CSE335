/**
 * \file Source.cpp
 *
 * \author Andrew Decrem
 *
 * Source class that represents the source.
 *
 */
#include "pch.h"
#include "Source.h"
#include "Sink.h"


/**
 * Constructor
 */
CSource::CSource()
{

}

CSource::~CSource()
{

}


/**
 * Add sink
 * \param sink 
 */
void CSource::AddSink(CSink* sink)
{
	sink->SetSource(this);
	mSinks.push_back(sink);
}

/**
 * Set Rotation
 * \param rotation 
 */
void CSource::SetRotation(double rotation)
{
	for (auto sink : mSinks)
	{
		sink->SetRotation(rotation);
	}
}