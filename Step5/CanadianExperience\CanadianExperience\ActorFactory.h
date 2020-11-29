/**
 * \file ActorFactory.h
 *
 * \author Andrew Decrem
 *
 * Class for general actor factory
 */
#pragma once
#include <memory>
#include "Actor.h"
class CActorFactory
{
public:
    ///Constructor
	CActorFactory();
    //Destructor
	virtual ~CActorFactory();
    ///Pure virtual Create function, a shared pointer to the actor and create function
	virtual std::shared_ptr<CActor> Create() = 0;
};

