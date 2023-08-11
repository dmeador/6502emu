#include "cpu6502.h"

//constructor
CPU6502::CPU6502()
{
    //Init(NULL);
}

CPU6502::CPU6502(MEMORY* memory)
{
    Init(memory);
}

//virtual 
bool CPU6502::Init(MEMORY* memory)
{
    bool result = false;

    // map memory into processor
    mem = memory;
    return result;
}

//virtual 
bool CPU6502::Reset()
{
    bool result = false;

    // reset CPU6502

    return result;
}

//virtual 
int CPU6502::Execute()
{
    int result = false;

    // Execute CPU6502

    // Get OP Code from PC
    BYTE opcode = mem->memory[(unsigned int)PC];
    // 

    // return clock ticks consumed for instruction
    return result;
}
