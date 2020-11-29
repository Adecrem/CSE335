/**
* \file PruneGarden.h
*
* \author Andrew Decrem
*
*  prunes the garden
*/

#pragma once
#include "TileVisitor.h"
#include "TileGarden.h"
class CPruneGarden :
	public CTileVisitor
{
public:
	virtual void VisitGarden(CTileGarden* garden) override;
};

