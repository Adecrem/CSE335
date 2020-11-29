/**
 * \file HaroldHeadTop.h
 *
 * \author Andrew Decrem
 *
 * Harold Head top
 */
#pragma once
#include "HeadTop.h"
 /*

 * Harold head top

 */
class CHaroldHeadTop : public CHeadTop
{
public:
    ///Constructor that takes in name and filename
	CHaroldHeadTop(const std::wstring& name, const std::wstring& filename);
    ///Virtual destructor
	virtual ~CHaroldHeadTop();
    ///virtual Draw function that takes in graphics
	virtual void Draw(Gdiplus::Graphics* graphics) override;
};

