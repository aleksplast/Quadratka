#include "tests.h"
#include "header.h"
#include <TXLib.h>
#include <stdio.h>

int main(void)
{
    int counter = 0;

    int OkTests = 0;

    printf("---Testing solve_square_equation---\n");
    OkTests += test_solve_square_equation( 0,  0,  0,  3,  0,   0, &counter);
    OkTests += test_solve_square_equation( 0,  0,  1,  0,  0,   0, &counter);
    OkTests += test_solve_square_equation( 0,  1,  0,  1,  0,   0, &counter);
    OkTests += test_solve_square_equation( 0, -5,  3,  1,  0.6, 0, &counter);
    OkTests += test_solve_square_equation( 1,  4,  0,  2, -4,   0, &counter);
    OkTests += test_solve_square_equation( 1,  0, -9,  2, -3,   3, &counter);
    OkTests += test_solve_square_equation( 4,  0,  0,  1,  0,   0, &counter);
    OkTests += test_solve_square_equation( 1,  2,  1,  1, -1,   0, &counter);
    OkTests += test_solve_square_equation(10,  1,  10, 0,  0,   0, &counter);
    OkTests += test_solve_square_equation( 1, -5,  4,  2,  1,   4, &counter);
    printf("%d succesfull test out of 10\n", OkTests);

    OkTests = 0;
    counter = 0;
    printf("---Testing solve_linear_equation---\n");
    OkTests += test_solve_linear_equation( 0,  0,  3,  0, &counter);
    OkTests += test_solve_linear_equation( 0,  4,  0,  0, &counter);
    OkTests += test_solve_linear_equation( 4,  0,  1,  0, &counter);
    OkTests += test_solve_linear_equation( 5, 10,  1, -2, &counter);
    printf("%d succesfull test out of 4\n", OkTests);

    OkTests = 0;
    counter = 0;
    printf("---Testing iszero---\n");
    OkTests += test_iszero(1e-7,  false, &counter);
    OkTests += test_iszero(   1,  false, &counter);
    OkTests += test_iszero(   0,  true, &counter);
    OkTests += test_iszero(1e-15, true, &counter);
    printf("%d succesfull test out of 4\n", OkTests);

    OkTests = 0;
    counter = 0;
    printf("---Testing compare---\n");
    OkTests += test_compare(1,  1+1e-7, false, &counter);
    OkTests += test_compare(1,       6, false, &counter);
    OkTests += test_compare(2,       2, true, &counter);
    OkTests += test_compare(1, 1+1e-15, true, &counter);
    printf("%d succesfull test out of 4\n", OkTests);

    return 0;
}

int test_solve_square_equation(const double a, const double b, const double c, const int n_ans, const double x1_ans, const double x2_ans, int* const counter)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(n_ans));
    assert(isfinite(x1_ans));
    assert(isfinite(x2_ans));
    assert(counter != NULL);

    double x1 = 0, x2 = 0;
    int nRoots = 0;

    *counter += 1;

    nRoots = solve_square_equation(a, b, c, &x1, &x2);

    if (!(nRoots == n_ans && compare(x1, x1_ans) && compare(x2, x2_ans)))
    {
        SetColor(RED);

        printf("Test #%d\nFAILED:   nRoots = %d, x1 = %lf, x2 = %lf\n    \
        \rExpected: nRoots = %d, x1 = %lf, x2 = %lf\n",               \
        *counter, nRoots, x1, x2, n_ans, x1_ans, x2_ans);

        SetColor(WHITE);

        return 0;
    }
    else
    {
        SetColor(GREEN);

        printf("Test #%d succeeded\n", *counter);

        SetColor(WHITE);

        return 1;
    }
}

int test_solve_linear_equation(double b, double c, int n_ans, double x_ans, int* counter)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(n_ans));
    assert(isfinite(x_ans));
    assert(counter != NULL);

    double x = 0;
    int nRoots = 0;

    *counter += 1;

    nRoots = solve_linear_equation(b, c, &x);

    if (!(nRoots == n_ans && compare(x, x_ans)))
    {
        SetColor(RED);

        printf("Test #%d\nFAILED:   nRoots = %d, x = %lf\n    \
        \rExpected: nRoots = %d, x = %lf\n\033",        \
        *counter, nRoots, x, n_ans, x_ans);

        SetColor(WHITE);

        return 0;
    }

    else
    {
        SetColor(GREEN);

        printf("Test #%d succeeded\n", *counter);

        SetColor(WHITE);

        return 1;
    }
}

int test_iszero(const double a, const bool ans, int* const counter)
{
    assert(isfinite(a));
    assert(isfinite(ans));
    assert(counter != NULL);

    *counter += 1;

    if (!(iszero(a) == ans))
    {
        SetColor(RED);

        printf("Test #%d\nFAILED:   ans = %d\n    \
        \rExpected: ans = %d\n",        \
        *counter, iszero(a), ans);

        SetColor(WHITE);

        return 0;
    }

    else
    {
        SetColor(GREEN);

        printf("Test #%d succeeded\n", *counter);

        SetColor(WHITE);

        return 1;
    }
}

int test_compare(const double a, const double b, const bool ans, int* const counter)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(ans));
    assert(counter != NULL);

    *counter += 1;

    if (!(compare(a,b) == ans))
    {
        SetColor(RED);

        printf("Test #%d\nFAILED:   ans = %d\n    \
        \rExpected: ans = %d\n",        \
        *counter, compare(a,b), ans);

        SetColor(WHITE);

        return 0;
    }
    else
    {
        SetColor(GREEN);

        printf("Test #%d succeeded\n", *counter);

        SetColor(WHITE);

        return 1;
    }
}
