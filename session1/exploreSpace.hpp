#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "diplomacy.hpp"


class ExploreSpace
{
public:
    ExploreSpace(std::shared_ptr<IDiplomacy> diplomacyPtr):diplomacyPtr_{diplomacyPtr}{};
    void ExploreStart()
    {
        GotoOuterSpace();
        std::string alienBack;
        diplomacyPtr_->SayHello("Hello", alienBack);
        std::cout << "Alien say:" << alienBack << "\n";
        diplomacyPtr_->ExchangeGift();
        diplomacyPtr_->SayBye("see you");
        ReturnToEarth();
    }
private:
    std::shared_ptr<IDiplomacy> diplomacyPtr_;
    void GotoOuterSpace()
    {
        std::cout << "we are in outer space now....\n";
    }

    void ReturnToEarth()
    {
        std::cout << "working finished, we are backing to earth now...\n";
    }

};
