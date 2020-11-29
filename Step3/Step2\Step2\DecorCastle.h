/**
 * \file DecorCastle.h
 *
 * \author Andrew Decrem
 */
#pragma once

#include <memory>
#include "Item.h"
#include "Aquarium.h"

class CDecorCastle : public CItem
{
public:
	CDecorCastle(CAquarium* aquarium);

	CDecorCastle() = delete;

	CDecorCastle(const CDecorCastle&) = delete;

};

