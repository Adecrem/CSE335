/**
 * \file Blower.cpp
 *
 * \author Andrew Decrem
 *
 * Blower class, technically my WorkingMachine class.
 *
 * Pretty much based off of the provided machine class, since we are not using that.
 */
#include "pch.h"
#include "Component.h"
#include "Motor.h"
#include "Blower.h"

 /**
  * Advance function (advised on website)
  * \param delta
  */
void CBlower::AdvanceFrame(double delta)
{

    for (auto component : mComponents)

    {

        component->AdvanceFrame(delta);

    }

}


 /**
  * Add to component
  * \param component
  */
void CBlower::AddComponent(std::shared_ptr<CComponent> component)
{
    component->SetBlowerMachine(this);
    mComponents.push_back(component);
}

/**
 * Drawmachine and add to component
 * \param graphics 
 * \param x 
 * \param y 
 */
void CBlower::DrawMachine(Gdiplus::Graphics* graphics, int x, int y)
{
	for (auto component : mComponents)
	{
		component->Draw(graphics, x, y);
	}
}

/**
 * Set time of motor to run correctly.
 * \param time 
 */
void CBlower::SetTime(double time)
{

	for (auto motor : mMotors)
	{

		motor->SetRotation(time);

	}

}
