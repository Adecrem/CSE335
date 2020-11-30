/**
 * \file Component.cpp
 *
 * \author Andrew Decrem
 *
 * Component class representing the components
 *
 */
#include "pch.h"
#include "Component.h"

CComponent::CComponent()
{

}

CComponent::~CComponent()
{

}

void CComponent::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	DrawPolygon(graphics, x + GetPosition().X, y + GetPosition().Y);
}