#pragma once

#include "cpu_types.h"

class MEMORY 
{
public:
    MEMORY() {}; // constructor
    virtual ~MEMORY();// destructor
    bool Init(unsigned int size);
    BYTE* memory;
    unsigned int size;
};
