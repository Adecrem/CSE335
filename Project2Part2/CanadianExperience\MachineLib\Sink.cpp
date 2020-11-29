/**
 * \file Sink.cpp
 *
 * \author Andrew Decrem
 *
 * Sink class
 *
 */
#include "pch.h"
#include "Sink.h"
#include "Component.h"


/**
 * Constructor 
 */
CSink::CSink()
{

}


/**
 * Destructor
 */
CSink::~CSink()
{

}


/**
 * Set the rotation
 * \param RPM 
 */
void CSink::SetRotation(double RPM)
{
	mRPM = RPM * 1.0;
	GetComponent()->Update(this);
}