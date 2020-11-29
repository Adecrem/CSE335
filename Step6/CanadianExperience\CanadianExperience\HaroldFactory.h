/**
 * \file HaroldFactory.h
 *
 * \author Andrew Decrem
 *
 * Harold factory class
 */
#pragma once
#include "Actor.h"
#include "ActorFactory.h"
/*

* Harold factory

*/
class CHaroldFactory : public CActorFactory
{
public:
    ///Constructor
	CHaroldFactory();
    ///Virtual destructor
	virtual ~CHaroldFactory();
    ///Shared pointer for create function
	std::shared_ptr<CActor> Create();
};

