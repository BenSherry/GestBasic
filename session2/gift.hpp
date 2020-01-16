#pragma once

#include <iostream>
#include <string>

class Gifts
{
public:
    Gifts(std::string name, std::string origin, std::string purpose):
        name_{name},
        origin_{origin},
        purpose_{purpose}{};
    std::string GetName()
    {
        return name_;
    }
    std::string GetOrigin()
    {
        return origin_;
    }

    std::string GetPurpose()
    {
        return purpose_;
    }
    
private:
  std::string name_;
  std::string origin_;
  std::string purpose_;
};
