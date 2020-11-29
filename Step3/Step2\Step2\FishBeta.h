/**
 * \file FishBeta.h
 *
 * \author Andrew Decrem
 *
 * Class the implements a Beta fish
 */

#pragma once

#include <memory>
#include "Xmlnode.h"
#include "Fish.h"

 /**
  * Implements a Beta fish
  */
class CFishBeta :
    public CItem
{
public:
    CFishBeta(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta &) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};

