#include "linear_congruential_generator.h"
#include <stdio.h>

unsigned int lcg_execute(unsigned int* lcg, unsigned int aref, unsigned int cref, unsigned int mref) {
    *lcg = (aref * (*lcg) + cref) % mref;
    return *lcg;
}

// ------------------------- TESTS -------------------------
void lcg_test_0() {
    unsigned int aref = 1664525;
    unsigned int cref = 1013904223;
    unsigned int mref = 1 << 31;
    unsigned int lcg = 42;

    for (unsigned int i = 0; i < 10; ++i) {
        printf("%u\n", lcg_execute(&lcg, aref, cref, mref));
    }
}
// ---------------------------------------------------------