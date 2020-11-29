/**
* \file TileGarden.h
*
* \author Andrew Decrem
*
*  Represents the garden class
*/

#pragma once
#include "Tile.h"
#include "TileVisitor.h"
class CTileGarden :
	public CTile
{
public:

	/** Accept a visitor
* \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor* visitor) override { visitor->VisitGarden(this); }


	void CTileGarden::Update(double elapsed);

	enum class PruningStates { Pruned, Overgrown1, Overgrown2, Overgrown3, Overgrown4 };

private:
	/// The current garden pruning state
	PruningStates mPruningState = PruningStates::Pruned;

};

