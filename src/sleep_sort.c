#include "sleep_sort.h"
#include <assert.h>
#include <process.h>
#include <stdio.h>

unsigned int __stdcall sleepSort_thread(void* data) {
    int* cast = (int*) data;
    int sec = *cast;

    Sleep(sec * 1000);
    printf("%d, ", sec);
}

void sleepSort_execute(int* array, size_t length) {
    // TODO: Port this to UNIX later on.

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