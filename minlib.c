#include "minlib.h"
#include "memory.h"

void write_word(int address, int word){
  int *a = (int*) address;
  *a = word;
}

void write_byte(int address, char byte){
  char *a = (char*) address;
  *a = byte;
}

int read_word(int address){
  int *a = (int*) address;
  return *a;
}


// GetSystemTick and sleep functions by xerpi

unsigned long long GetSystemTick(void)
{
    register unsigned long lo64 asm ("r0");
    register unsigned long hi64 asm ("r1");
    asm volatile ( "SVC 0x28" : "=r"(lo64), "=r"(hi64) );
    return ((unsigned long long)hi64<<32) | (unsigned long long)lo64;
}

void nsleep(unsigned long long ns)
{
    unsigned long long ticks = ns;
    unsigned long long start = GetSystemTick();
    while ((GetSystemTick() - start) < ticks);
}

void usleep(unsigned long long us)
{
    unsigned long long ticks = us * TICKS_PER_USEC;
    unsigned long long start = GetSystemTick();
    while ((GetSystemTick() - start) < ticks);
}

void msleep(unsigned long long ms)
{
    unsigned long long ticks = ms * TICKS_PER_MSEC;
    unsigned long long start = GetSystemTick();
    while ((GetSystemTick() - start) < ticks);  
}

void sleep(unsigned long long s)
{
    unsigned long long ticks = s * TICKS_PER_SEC;
    unsigned long long start = GetSystemTick();
    while ((GetSystemTick() - start) < ticks); 
}
