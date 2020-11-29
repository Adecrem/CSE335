/**
 * \file PolyDrawable.h
 *
 * \author Andrew Decrem
 *
 * Sparty head Top edits
 */
#pragma once
#include "HeadTop.h"
/**
 *
 * Making the sparty head possible and able to make edits
 *
 */
class CSpartyHeadTop : public CHeadTop
{
public:
	CSpartyHeadTop(const std::wstring& name, const std::wstring& filename);
    ///Virtual deconstructor
	virtual ~CSpartyHeadTop();
    ///Virtual draw
	virtual void Draw(Gdiplus::Graphics* graphics) override;
};

