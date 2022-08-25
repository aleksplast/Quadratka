#include "header.h"
#include <math.h>
#include <conio.h>
#include <ctype.h>

//#define DEBUG

#ifndef DEBUG
#define DBG if(false)
#else
#define DBG if(true)
#endif

//!--------------------------------
//! @brief Used for output, shows the number of roots
//!--------------------------------

enum Number_of_Roots
{
    ZERO_ROOTS,  //return if square equation has zero roots
    ONE_ROOT,   //return if square equation has one root
    TWO_ROOTS,  //return if square equation has two roots
    INFINITE_ROOTS  //return if square equation has infinite number of roots
} ;

double coeff(double a)
{
    bool flag = true;
    char ch = 0;
    int counter = 0;

    fflush(stdin);

    printf("Enter the coefficient\n");

    while (true)
    {
        counter = 0;
        flag = true;

        fflush(stdin);

        if (scanf("%lf", &a) == 1)
        {
            while ((ch = getchar()) != '\n')
                counter += 1;
            if (counter == 0)
                return a;
            else
                printf("Wrong input, enter a real number\n");
        }
        else if (flag)
            printf("Wrong input, enter a real number\n");
    }
}

int solve_linear_equation(double b, double c, double* x1)
{
    DBG printf("Your equation: %.2lf * x + %lf = 0\n", b, c);

    if (!iszero(b))
    {
        *x1 = -c/b;
        return ONE_ROOT;
    }

    else if (!iszero(c))
        return ZERO_ROOTS;
    else
        return INFINITE_ROOTS;
}

int solve_square_equation(double a, double b, double c, double* x1, double* x2)
{
    double discr = 0, sqrt_discr = 0, x1_temp = 0, x2_temp = 0;

    if (iszero(a))
        return solve_linear_equation(b,c, x1);
    else
    {
        DBG printf("Your equation: %.2lf * x^2 + %.2lf * x + %.2lf = 0\n", a, b, c);
        discr = b * b - 4 * a * c;

            if (discr > 0)
            {
                sqrt_discr = sqrt(discr);

                x1_temp = (-b + sqrt_discr) / (2 * a);
                x2_temp = (-b - sqrt_discr) / (2 * a);

                if (x1_temp < x2_temp)
                {
                    *x1 = x1_temp;
                    *x2 = x2_temp;
                }
                else
                {
                    *x1 = x2_temp;
                    *x2 = x1_temp;
                }

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

bool compare(double a, double b)
{
    if (fabs(a-b) < EPSILON)
        return true;
    else
        return false;
}
