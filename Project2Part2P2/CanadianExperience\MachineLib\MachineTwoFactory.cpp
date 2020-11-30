/**
 * \file MachineTwoFactory.cpp
 *
 * \author Andrew Decrem
 *
 * Factory that draws the second machine
 *
 */
#include "pch.h"
#include "MachineTwoFactory.h"
#include "Blower.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "Sink.h"
#include "Source.h"
#include "SnowMachine.h"
#include "MachineOneFactory.h"

using namespace std;
using namespace Gdiplus;


/**
 * Second machine constructor
 */
CMachineTwoFactory::CMachineTwoFactory()
{

}


/**
 * Second machine destructor
 */
CMachineTwoFactory::~CMachineTwoFactory()
{

}

/**
 * Create second machines posts
 * \param x
 * \param y
 * \param wid
 * \param hit
 * \param color
 * \returns
 */
std::shared_ptr<CShape> CMachineTwoFactory::CreatePost(int x, int y, int wid, int hit, Gdiplus::Color color)
{
    auto post = make_shared<CShape>();
    post->Rectangle(-wid / 2, 0, wid, hit);
    post->SetColor(color);
    post->SetPosition(x, y);
    return post;
}


/**
 * Create second machine and have it function
 * Again with a few edits this is basically what was given on the website, I saw that for the second machine it has to face the other way however.
 * \returns 
 */
std::shared_ptr<CBlower> CMachineTwoFactory::Create()
{
    // The machine itself
    auto machine = make_shared<CBlower>(2);

    const int MotorX = 20;	// Motor X location
    const int Post1X = -70;	// Post X location
    const int Post2X = 80;	// Second post X location

    int Post1Height = 120;
    int Post2Height = 200;

    //
    // The base
    //
    auto base = make_shared<CShape>();
    int wid = 325;
    base->Rectangle(-wid / 2, 0, wid, 40);
    base->SetImage(L"images/base.png");
    machine->AddComponent(base);

    //
    // The motor
    //
    auto motor = make_shared<CMotor>(10);
    motor->SetPosition(MotorX, -38);
    motor->SetSpeed(1.0);
    machine->AddMotor(motor);
    machine->AddComponent(motor);

    //
    // The snow blower
    //
    auto blower = make_shared<CSnowMachine>();
    machine->AddComponent(blower);
    blower->SetPosition(Post1X, -150);
    blower->SetRotation(0.15);
    machine->AddComponent(blower);

    //
    // Post to hold the first pulley
    // Must be added before the motor pulley so it draws behind the belt
    //
    auto post1 = CreatePost(Post1X, -40, 20, Post1Height, Color(10, 10, 10));
    machine->AddComponent(post1);

    //
    // Post to hold the second pully
    //
    auto post2 = CreatePost(Post2X, -40, 20, Post2Height, Color(10, 10, 10));
    machine->AddComponent(post2);

    //
    // The pulley driven by the motor
    // Radius=15pixels
    //
    auto pulley1 = make_shared<CPulley>(15);
    pulley1->SetImage(L"images/electric-wheel.png");
    pulley1->SetPosition(MotorX, -38 - CMotor::Size / 2);
    pulley1->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley1);

    // This is how I make a connection from a source to a sink.
    // This is the case where they are driven at the same speed.
    motor->GetSource()->AddSink(pulley1->GetSink());

    //
    // The pulley on the snow blower. Driven by the motor pulley.
    // Radius=40pixels
    //
    auto pulley2 = make_shared<CPulley>(40);
    pulley2->SetImage(L"images/pulley.png");
    pulley2->SetPosition(Post1X, post1->GetPosition().Y - Post1Height + 10);
    pulley2->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley2);

    pulley2->GetSource()->AddSink(blower->GetSink());

    // This is how I make a connection from a pully
    // to another pully using a belt.
    pulley1->DrivePulley(pulley2);

    //
    // Pulley directly driven by that pulley
    // Radius=15px
    //
    auto pulley3 = make_shared<CPulley>(15);
    pulley3->SetImage(L"images/pulley2.png");
    pulley3->SetPosition(pulley2->GetPosition().X, pulley2->GetPosition().Y);
    machine->AddComponent(pulley3);

    pulley2->GetSource()->AddSink(pulley3->GetSink());

    //
    // Pully on the second post
    //
    auto pulley4 = make_shared<CPulley>(40);
    pulley4->SetImage(L"images/pulley.png");
    pulley4->SetPosition(Post2X, post2->GetPosition().Y - Post2Height + 10);
    pulley4->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley4);

    pulley3->DrivePulley(pulley4);

    // The flag
    auto flag = make_shared<CShape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(L"images/flag.png");
    flag->SetPosition(pulley4->GetPosition().X, pulley4->GetPosition().Y);
    machine->AddComponent(flag);

    pulley4->GetSource()->AddSink(flag->GetSink());

    return machine;
}