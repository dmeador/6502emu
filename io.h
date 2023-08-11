#pragma once
#include <string>
#include <cstdio>

class IO 
{
    public:
    IO() {};
    virtual ~IO() {};
    bool Init() { return false; };
};
