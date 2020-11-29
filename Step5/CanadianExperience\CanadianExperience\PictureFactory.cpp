/**
 * \file PictureFactory.cpp
 *
 * \author Andrew Decrem
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "ImageDrawable.h"
#include "SpartyFactory.h"
using namespace std;
using namespace Gdiplus;

/** Factory method to create a new picture.
* \returns The created picture
*/
/** Constructor */
CPictureFactory::CPictureFactory() {

}
/** Destructor */
CPictureFactory::~CPictureFactory() {

}

/** Creates the two Characters
* \param graphics The graphics that is being drawn
*
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();
    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI =
        make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);
    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sFactory;
    auto sparty = sFactory.Create();

    // This is where Sparty will start out.
    sparty->SetPosition(Point(200, 500));

    picture->AddActor(sparty);

    return picture;
}