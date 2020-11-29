/**
 * \file SpartyFactory.h
 *
 * \author Andrew Decrem
 *
 * Sparty Factory class
 */
#pragma once
#include "ActorFactory.h"
#include "Actor.h"
 /**
  *
  * Sparty factory class
  *
  */
class CSpartyFactory : public CActorFactory
{
public:
    ///Constructor
	CSpartyFactory();
    ///Virtual deconstructor
	virtual ~CSpartyFactory();
    ///Shared create function
	std::shared_ptr<CActor> Create();
};

