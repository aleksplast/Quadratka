#include "header.h"

void test_equation(double a, double b, double c, int n_ans, double x1_ans, double x2_ans);

int main(void)
{
    test_equation(1, 2, 1, 1, -1, 0);
    test_equation(0, 0, 0, 3, 0, 0);
    test_equation(0, 0, 1, 0, 0, 0);
    test_equation(0, 1, 0, 1, 0, 0);
    test_equation(0, -5, 3, 1, 0.6, 0);
    test_equation(1, -5, 4, 2, 1, 4);
    return 0;
}



void test_equation(double a, double b, double c, int n_ans, double x1_ans, double x2_ans)
{
    double x1 = 0, x2 = 0;
    int nRoots = 0;
    nRoots = solve_square_equation(a,b,c, &x1, &x2);
    if (!(nRoots == n_ans && x1 == x1_ans && x2 == x2_ans))
    {
        printf("FAILED: nRoots = %d, x1 = %lf, x2 = %lf\n    \
        Expected: nRoots = %d, x1 = %lf, x2 = %lf\n",        \
        nRoots, x1, x2, n_ans, x1_ans, x2_ans);
    }
    printf("test success\n");
}
