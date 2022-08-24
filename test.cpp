#include "header.h"

int main(void)
{
    double x1 = 0, x2 = 0;
    int nRoots = 0;
    nRoots = solve_square_equation(1,2,1, &x1, &x2);
    if (!(nRoots == 1 && x1 == -1 && iszero(x2)))
    {
        printf("FAILED: nRoots = %d, x1 = %lf, x2 = %lf\n    \
        Expected: nRoots = %d, x1 = %lf, x2 = %lf\n",        \
        nRoots, x1, x2, 1, -1, 0);
    }

    x1 = 0, x2 = 0;
    nRoots = solve_square_equation(0,0,0, &x1, &x2);
    if (!(nRoots == 3 && iszero(x1) && iszero(x2)))
    {
        printf("FAILED: nRoots = %d, x1 = %lf, x2 = %lf\n    \
        Expected: nRoots = %d, x1 = %lf, x2 = %lf\n",        \
        nRoots, x1, x2, 3, 0, 0);
    }
    return 0;
}
