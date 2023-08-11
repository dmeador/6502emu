#include "memory.h"
#include <cstdio>
#include <memory>

bool MEMORY::Init(unsigned int size)
{
    this->size = size;
    memory = new BYTE [size];
    return (memory != NULL);
}

MEMORY::~MEMORY()
{
    if(memory) delete [] memory;
    memory = NULL;
    size = 0;
}