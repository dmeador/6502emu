#include "cpu.h"


/*
bit 7  P.N  Negative*
bit 6  P.V  oVerflow
bit 5   -   unused
bit 4  P.B  BRK was executed

bit 3  P.D  enable binary coded Decimal
bit 2  P.I  block IRQ Interrupts
bit 1  P.Z  Zero
bit 0  P.C  Carry
*/
#include "cpu_types.h"
#include "memory.h"

struct status_reg {
    BYTE P_C:1; //P.C Carry
    BYTE P_Z:1; //P.Z Zero
    BYTE P_I:1; //P.I block IRQ Interrupts
    BYTE P_D:1; //P.D Binary Coded Decimal enable
    BYTE P_B:1; //P.B BRK was executed
    BYTE unused6:1; //- unused
    BYTE P_V:1; //P.V Overflow
    BYTE P_N:1; //P.N Negative 
};

struct cpu6502 {
    status_reg status;  // PSW (Program Status Word) : 8-bit register
                        // https://www.csh.rit.edu/~moffitt/docs/6502.html#FLAGS
    WORD PC;            // PC (Program Counter) : 16-bit register
                        // https://www.csh.rit.edu/~moffitt/docs/6502.html#FLOW
    BYTE AC;            // Accumulator
    BYTE X;             // X register
    BYTE Y;             // Y register
    BYTE SP;            // SP (Stack Pointer) : 8 bit : Valid range 01:FF to 01:00
                        // https://www.csh.rit.edu/~moffitt/docs/6502.html#STACK

};

class CPU6502 : public CPU
{
public:
    CPU6502(); // constructor
    CPU6502(MEMORY* memory); // constructor
    virtual ~CPU6502() {}

    struct status_reg status;   // PSW (Program Status Word) : 8-bit register
                                // https://www.csh.rit.edu/~moffitt/docs/6502.html#FLAGS
    BYTE AC;    // Accumulator
                // https://www.csh.rit.edu/~moffitt/docs/6502.html#FLOW
    WORD PC;    // PC (Program Counter) : 16-bit register
    BYTE X;     // X register
    BYTE Y;     // Y register
    BYTE SP;    // SP (Stack Pointer) : 8 bit : Valid range 01:FF to 01:00
                // https://www.csh.rit.edu/~moffitt/docs/6502.html#STACK

    virtual bool Init(MEMORY* memory);
    virtual bool Reset();
    virtual int  Execute();
private:
    
};