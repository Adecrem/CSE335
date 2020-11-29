/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background2.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    //Add the first machine
    shared_ptr<CMachineDrawable> machine = make_shared <CMachineDrawable>(L"machine", 1);
    shared_ptr<CActor> machineActor = make_shared<CActor>(L"Machine Actor");
    machine->SetPosition(Point(600, 600));
    machineActor->AddDrawable(machine);
    picture->AddActor(machineActor);

    //Add the second machine
    shared_ptr<CMachineDrawable> machine2 = make_shared <CMachineDrawable>(L"machine", 2);
    shared_ptr<CActor> machineActor2 = make_shared<CActor>(L"Machine Actor");
    machine2->SetPosition(Point(400, 600));
    machineActor2->AddDrawable(machine2);
    picture->AddActor(machineActor2);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 600));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(600, 600));
    picture->AddActor(sparty);

    return picture;
}
