// https://www.geeksforgeeks.org/sleep-sort-king-laziness-sorting-sleeping/

#ifndef SLEEP_SORT_H
#define SLEEP_SORT_H

#include <stdlib.h>

#ifdef DSAA_WINAPI
#include <windows.h>

unsigned int __stdcall sleepSort_thread(void* data);
#endif// DSAA_WINAPI

void sleepSort_execute(int* array, size_t length);

// ------------------------- TESTS -------------------------
void sleep_sort_test_0();
// ---------------------------------------------------------

#endif//! SLEEP_SORT_H