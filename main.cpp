#include "header.h"
#include <stdio.h>
#include <assert.h>
#include <conio.h>
#include <math.h>

int main(void)
{
    int test=1;

    printf("This program will solve quadratic equations with standard form of ax^2 + bx + c = 0\n");

    while(test == 1)
    {
        int roots = 0;
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        a = coeff(a);
        b = coeff(b);
        c = coeff(c);

        assert(isfinite(a));
        assert(isfinite(b));
        assert(isfinite(c));

        roots = solve_square_equation(a,b,c, &x1, &x2);

        output(roots, x1, x2);
        printf("Enter 1 to continue solving or 0 to end this program\n");
        scanf("%d", &test);
    }
    return 0;
}

