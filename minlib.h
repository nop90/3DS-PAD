#ifndef MINLIB_H
#define MINLIB_H

void write_byte(int address, char byte);
void write_word(int address, int word);
int read_word(int address);

#define TICKS_PER_SEC 0x80C0000
#define TICKS_PER_MSEC (TICKS_PER_SEC/1000)
#define TICKS_PER_USEC (TICKS_PER_MSEC/1000)

unsigned long long GetSystemTick(void);
void nsleep(unsigned long long ns);
void usleep(unsigned long long us);
void msleep(unsigned long long ms);
void sleep(unsigned long long s);


#endif
