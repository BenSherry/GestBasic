#pragma once

#include <iostream>
#include <string>

#include "gift.hpp"

class IDiplomacy
{
public:
    virtual bool SayHello(std::string, std::string&) = 0;
    virtual Gifts ExchangeGift(Gifts&) = 0;
    virtual bool SayBye(std::string) = 0;
};
