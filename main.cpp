#include <math.h>
#include <stdio.h>

#include "header.h"

//!--------------------------------
//! @brief Main function of the program
//!--------------------------------
int main()
{
    int proceed = 1;

    printf("This program will solve quadratic equations with standard form of ax^2 + bx + c = 0\n");

    while(proceed == 1)
    {
        double x1 = 0, x2 = 0;

        double a = coeff();
        double b = coeff();
        double c = coeff();

        int roots = solve_square_equation(a, b, c, &x1, &x2);

        output(roots, x1, x2);
        printf("Enter 1 to continue solving or 0 to end this program\n");
        scanf("%d", &proceed);
    }
    return 0;
}

