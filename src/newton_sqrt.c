#include "newton_sqrt.h"
#include <assert.h>
#include <math.h>

float newton_sqrt(float number) {
    if (number <= 0.0f) return 0.0f;

    float tolerance = 0.00001f;
    float estimate = number;

    float root;
    while (1) {
        root = 0.5f * (estimate + (number / estimate));
        float difference = root - estimate;

        if (fabsf(difference) < tolerance) break;
        estimate = root;
    }

    return root;
}

// ------------------------- TESTS -------------------------
void newton_sqrt_test_0() {
    float first = newton_sqrt(25);
    assert(first == 5.0f);

    float second = newton_sqrt(36);
    assert(second == 6.0f);

    float third = newton_sqrt(8);
    assert(third == 2.82842712475f);
}
// ---------------------------------------------------------