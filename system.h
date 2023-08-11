#include "cpu.h"
#include "memory.h"
#include "io.h"

// Base Class : SYSTEM
class SYSTEM
{
public: 
    SYSTEM() {};         // constructor
    virtual ~SYSTEM() {} // destructor
    virtual bool Init() = 0;
    virtual bool Run() = 0;
    virtual bool ClockTick() = 0;
    CPU* cpu;
    MEMORY* memory;
    IO* io;

};
