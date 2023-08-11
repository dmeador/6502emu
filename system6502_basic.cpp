#include "system6502_basic.h"
#include <ctime>
#include "Logger.hpp"

 //  virtual 
 bool SYSTEM6502_Basic::Init()
 {
    SYSTEM::cpu = &cpu6502;
    SYSTEM::memory = &mem6502;
    SYSTEM::io = &io6502;
    LOG( "SYSTEM6502_Basic INIT" );
    mem6502.Init(0xFFFF);
    cpu6502.Init(memory);
    return 0;
 }
 
///  virtual 
 bool SYSTEM6502_Basic::Run()
 {
    // perform read inputs from IO
    // perform process CPU
    cpu->Execute();
    // perform write outputs to IO

    return true;

 }
 
 //  virtual 
 bool SYSTEM6502_Basic::ClockTick()
 {
    bool result = false;
    // perform read inputs from IO
    // perform process CPU
    // perform write outputs to IO
    struct timespec requested_time;
    struct timespec remaining;
    requested_time.tv_nsec = 1000*1000; // 1 ms
    requested_time.tv_nsec = 0; // sec
    nanosleep(&requested_time, &remaining);
    if (remaining.tv_nsec || remaining.tv_sec )
    {
        result = true;
    }
    return result;
 }
 