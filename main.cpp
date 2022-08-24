#include "header.h"

#define EPSILON pow(10, -10)

enum Number_of_Roots
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS
} ;

double coeff(double a)
{
    fflush(stdin);

    printf("Enter the coefficient\n");

    if (scanf("%lf", &a) == 1)
        return a;
    else
    {
        printf("Wrong input, enter a real number\n");

        return coeff(a);
    }
}

int solve_linear_equation(double b, double c, double* x1)
{
    printf("Your equation: %.2lf * x + %lf = 0\n", b, c);

    if (!iszero(b))
    {
        *x1 = -c/b;
        return ONE_ROOT;
    }

    else if (iszero(b) && !iszero(c))
        return ZERO_ROOTS;
    else
        return INFINITE_ROOTS;
}

int solve_quadratic_equation(double a, double b, double c, double* x1, double* x2)
{
    double discr = 0, sqrt_discr;

    if (iszero(a))
        return solve_linear_equation(b,c, x1);
    else
    {
        printf("Your equation: %.2lf * x^2 + %.2lf * x + %.2lf = 0\n", a, b, c);
        discr = b * b - 4 * a * c;

            if (discr > 0)
            {
                sqrt_discr = sqrt(discr);

                *x1 = (-b + sqrt_discr) / (2 * a);
                *x2 = (-b - sqrt_discr) / (2 * a);

                return TWO_ROOTS;
            }

            else if (iszero(discr))
            {
                *x1 = -b / (2 * a);

                return ONE_ROOT;
            }

            else
                return ZERO_ROOTS;
        }
}

bool iszero(double n)
{
    if (fabs(n) < EPSILON)
        return true;
    else
        return false;
}

void output(int roots, double x1, double x2)
{
    switch(roots)
    {
        case ONE_ROOT:
            printf("Equation has 1 solution: x = %lf\n", x1);
            break;
        case TWO_ROOTS:
            printf("Equation has 2 solutions: x1 = %lf and x2 = %lf\n", x1, x2);
            break;
        case ZERO_ROOTS:
            printf("Equation has no real solutions\n");
            break;
        case INFINITE_ROOTS:
            printf("Equation has infinite number of solutions\n");
            break;
        default:
            break;
    }
}


