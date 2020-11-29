/**
 * \file SpartyFactory.cpp
 *
 * \author Andrew Decrem
 */
#include "pch.h"
#include "SpartyFactory.h"
#include <memory>
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"
#include "SpartyHeadTop.h"

using namespace std;
using namespace Gdiplus;

/** Constructor */
CSpartyFactory::CSpartyFactory()
{

}

/** Destructor */
CSpartyFactory::~CSpartyFactory()
{

}
//Used gimp and loaded in images to try to find the center, this was as close as I could get
std::shared_ptr<CActor> CSpartyFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Sparty");

	auto torso = make_shared<CImageDrawable>(L"Torso", L"images/sparty_torso.png");
	torso->SetCenter(Point(80, 210));
	torso->SetPosition(Point(0, -115));
	actor->SetRoot(torso);

	auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/sparty_lleg.png");
	lleg->SetCenter(Point(0, 0));
	lleg->SetPosition(Point(-10, -60));
	torso->AddChild(lleg);

	auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/sparty_rleg.png");
	rleg->SetCenter(Point(75, 0));
	rleg->SetPosition(Point(10, -60));
	torso->AddChild(rleg);

	auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/sparty_larm.png");
	larm->SetCenter(Point(0, 0));
	larm->SetPosition(Point(25, -220));
	torso->AddChild(larm);

	auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/sparty_rarm.png");
	rarm->SetCenter(Point(120, 0));
	rarm->SetPosition(Point(-25, -215));
	torso->AddChild(rarm);

	auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/sparty_lhead.png");
	headb->SetCenter(Point(55, 0));
	headb->SetPosition(Point(0, -220));
	torso->AddChild(headb);

	auto headt = make_shared<CSpartyHeadTop>(L"Head Top", L"images/sparty_head.png");
	headt->SetCenter(Point(50, 150));
	headt->SetPosition(Point(0, 10));
	headb->AddChild(headt);



	actor->AddDrawable(larm);
	actor->AddDrawable(rarm);
	actor->AddDrawable(rleg);
	actor->AddDrawable(lleg);
	actor->AddDrawable(torso);
	actor->AddDrawable(headb);
	actor->AddDrawable(headt);

	return actor;
}