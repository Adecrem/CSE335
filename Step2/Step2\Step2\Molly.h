/**
 * \file Molly.h
 *
 * \author Andrew Decrem
 */
#pragma once

#include <memory>

#include "Item.h"

class CMolly : public CItem
{
public:
	CMolly(CAquarium* aquarium);//initialize aquarium

	CMolly() = delete;//delete default

	CMolly(const CMolly &) = delete;

	bool HitTest(int, int);//hit test

	virtual void Draw(Gdiplus::Graphics* graphics) override;//draw over ride

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;//fish image private member function

};

