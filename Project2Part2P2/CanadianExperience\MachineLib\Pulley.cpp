/**
 * \file Pulley.cpp
 *
 * \author Andrew Decrem
 *
 * Pulley class that represents the pulley in the machine
 *
 */
#include "pch.h"
#include "Source.h"
#include "Sink.h"
#include "Pulley.h"
using namespace std;
using namespace Gdiplus;


/**
 * Pulley given diameter
 * \param diameter 
 */
CPulley::CPulley(double diameter)
{
	mSink.SetComponent(this);
	mDiameter = diameter;
	Circle(diameter);
}


/**
 * Destructor
 */
CPulley::~CPulley()
{

}


/**
 * Update sink
 * \param sink 
 */
void CPulley::Update(CSink* sink)
{
	auto rotation = mSink.GetRotation();
	SetRotation(rotation);
}

/**
 * Drive the pulley
 * \param pulley
 */
void CPulley::DrivePulley(std::shared_ptr<CPulley> pulley)
{
	mPulley = pulley;

}

/**
 * Draw function 
 * \param graphics 
 * \param x 
 * \param y 
 */
void CPulley::Draw(Gdiplus::Graphics* graphics, int x, int y)
{

	if (mPulley != nullptr)
	{
		auto saveSM = graphics->GetSmoothingMode();
		graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);
		//DrawBelt(graphics, x, y);
		auto pen = new Pen(Color::Black, 3.0f);
		int x1 = this->GetPosition().X;
		int y1 = this->GetPosition().Y;
		int x2 = mPulley->GetPosition().X;
		int y2 = mPulley->GetPosition().Y;
		auto r1 = mDiameter - 3;
		auto r2 = mPulley->GetDiameter() - 3;
		double theta = atan2((y2 - 1), (x2 - x1));
		double Dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		double phi = asin((r2 - r1) / Dist);
		double top = theta + phi + M_PI / 2;
		double bottom = theta - phi - M_PI / 2;
		double t_p1_x1 = (x + x1) + r1 * cos(top);
		double t_p2_x2 = (x + x2) + r2 * cos(top);
		double t_p1_y1 = (y + y1) + r1 * sin(top);
		double t_p2_y2 = (y + y2) + r2 * sin(top);
		double b_p1_x1 = (x + x1) + r1 * cos(bottom);
		double b_p2_x2 = (x + x2) + r2 * cos(bottom);
		double b_p1_y1 = (y + y1) + r1 * sin(bottom);
		double b_p2_y2 = (y + y2) + r2 * sin(bottom);
		graphics->DrawLine(pen, Gdiplus::Point(t_p1_x1, t_p1_y1), Gdiplus::Point(t_p2_x2, t_p2_y2));
		graphics->DrawLine(pen, Gdiplus::Point(b_p1_x1, b_p1_y1), Gdiplus::Point(b_p2_x2, b_p2_y2));
		CComponent::Draw(graphics, x, y);
		graphics->SetSmoothingMode(saveSM);
	}
	CComponent::Draw(graphics, x, y);
}

/**
 * Set the rotation of the belt
 * \param rotation 
 */
void CPulley::SetRotation(double rotation)
{
	CComponent::SetRotation(rotation);
	mSource.SetRotation(rotation);

	if (mPulley != nullptr)
	{
		double rotation = (GetRotation() * mDiameter) / mPulley->GetDiameter();
		mPulley->SetRotation(rotation);
	}
}
