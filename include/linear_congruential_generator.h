// https://en.wikipedia.org/wiki/Linear_congruential_generator

#ifndef LINEAR_CONGRUENTIAL_GENERATOR_H
#define LINEAR_CONGRUENTIAL_GENERATOR_H

unsigned int lcg_execute(unsigned int* lcg, unsigned int aref, unsigned int cref, unsigned int mref);

// ------------------------- TESTS -------------------------
void lcg_test_0();
// ---------------------------------------------------------

#endif//! LINEAR_CONGRUENTIAL_GENERATOR_H