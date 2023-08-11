#include "stdio.h"
#include "system6502_basic.h"


int main(int argc, char* argv[])
{
    printf("6502 Emulator\n");
    SYSTEM6502_Basic system;

    system.Init();
    system.Run();
    return 0;
}
