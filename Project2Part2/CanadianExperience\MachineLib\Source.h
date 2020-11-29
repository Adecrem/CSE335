/**
 * \file Source.h
 *
 * \author Andrew Decrem
 *
 * Class that represents source part of the actual machine.
 *
 */
#pragma once
#include <memory>
#include <vector>

class CSink;

class CSource
{
public:
    ///Constructor
	CSource();

    ///Destructor
    ~CSource();

    ///Copy constructor disable
	CSource(const CSource&) = delete;

    ///Assignment operator disable
	void operator=(CSink* sink) = delete;

    ///Add sink 
	void AddSink(CSink* sink);

    ///Set rotation
	void SetRotation(double rotation);
private:

	std::vector<CSink*> mSinks; //< Vector for sink
};

