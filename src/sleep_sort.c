#include "sleep_sort.h"
#include <assert.h>
#ifdef DSAA_WINAPI
#include <process.h>
#endif// DSAA_WINAPI
#include <stdio.h>

#ifdef DSAA_WINAPI
unsigned int __stdcall sleepSort_thread(void* data) {
    int* cast = (int*) data;
    int sec = *cast;

    Sleep(sec * 1000);
    printf("%d, ", sec);
}
#endif// DSAA_WINAPI

void sleepSort_execute(int* array, size_t length) {
    // TODO: Port this to UNIX later on.
#ifdef DSAA_WINAPI
    assert(array != NULL);

    HANDLE* threadHandles = (HANDLE*) malloc(sizeof(HANDLE) * length);
    assert(threadHandles != NULL);

    for (size_t i = 0; i < length; i++) {
        threadHandles[i] = (HANDLE) _beginthreadex(NULL, 0, sleepSort_thread, &array[i], 0, NULL);
        assert(threadHandles[i] != NULL);
    }

    // Wait for all threads to finish.
    WaitForMultipleObjects((DWORD) length, threadHandles, TRUE, INFINITE);

    // Close allocated thread handles.
    for (size_t i = 0; i < length; i++) {
        CloseHandle(threadHandles[i]);
    }

    free(threadHandles);
#else
    printf("Sleep sort needs to be ported to your current OS first");
#endif// DSAA_WINAPI
}

// ------------------------- TESTS -------------------------
void sleep_sort_test_0() {
    size_t length = 10;
    int* array = (int*) malloc(sizeof(int) * length);
    assert(array != NULL);

    array[0] = 3;
    array[1] = 1;
    array[2] = 12;
    array[3] = 5;
    array[4] = 9;
    array[5] = 2;
    array[6] = 17;
    array[7] = 28;
    array[8] = 9;
    array[9] = 35;

    sleepSort_execute(array, length);

    free(array);
}
// ---------------------------------------------------------