#include <stdio.h>

#define DESIGN_PATTERN 0

void func0 (void) { }
void func1 (void) { }

typedef struct
{
  void (*func0)(void);
  void (*func1)(void);
}  funcptrs;

void (*pf[])(void) = {func0, func1};

// original jumptable function
void jumpTable(int c)
{
    pf[c]();
}

// jump table with design pattern applied
void jumpTable_dp(int c)
{
    switch (c) {
        case 0:
            func0();
            break;
        case 1:
            func1();
            break;
        default:
            break;
    }
}

void jumpTable_test()
{
    int c=0;

    #if DESIGN_PATTERN
        jumpTable_dp(c);
    #else
        jumpTable(c);
    #endif
}

int main(int argc, char *argv[])
{
    jumpTable_test();

    return 0;
}