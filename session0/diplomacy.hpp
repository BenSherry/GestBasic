#pragma once

#include <iostream>
#include <string>

class IDiplomacy
{
public:
    virtual bool SayHello(std::string) = 0;
    virtual void ExchangeGift() = 0;
    virtual bool SayBye(std::string) = 0;
};
