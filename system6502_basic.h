#include "system.h"

#include "cpu6502.h"
#include "memory.h"
#include "io.h"

// Base Class : SYSTEM
class SYSTEM6502_Basic : public SYSTEM
{
public: 
    SYSTEM6502_Basic() {};         // constructor
    virtual ~SYSTEM6502_Basic() {} // destructor
    virtual bool Init();
    virtual bool Run();
    virtual bool ClockTick();
   
    CPU6502 cpu6502;
    MEMORY mem6502;
    IO io6502;
};
