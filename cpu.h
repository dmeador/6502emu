
#pragma once
#include "memory.h"

class CPU
{
public:
    CPU() {};
    CPU(MEMORY* memory);
    virtual ~CPU() {};
    virtual bool Init(MEMORY* memory)=0;    //pure
    virtual bool Reset()=0;   //pure
    virtual int  Execute()=0; //pure
    MEMORY* mem;
private:
};

