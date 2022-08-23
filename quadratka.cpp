#include <stdio.h>
#include <math.h>
#include <assert.h>
#define EPSILON pow(10, -10)

double coeff(double a);
int solve_linear_equation(double b, double c, double* x1);
int solve_quadratic_equation(double a, double b, double c, double* x1, double* x2);
bool iszero (double n);
void output(int roots, double x1, double x2);
void square_equation(void);

int main(void)
{
    int test=1;
    char ch;
    printf("This program will solve quadratic equations with standard form of ax^2 + bx + c = 0\n");

    while(test == 1)
    {
        square_equation();
        printf("Enter 1 to continue solving or 0 to end this program\n");
        scanf("%d", &test);
    }
    return 0;
}

void square_equation(void)
{
    int roots = 0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    a = coeff(a);
    b = coeff(b);
    c = coeff(c);

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    roots = solve_quadratic_equation(a,b,c, &x1, &x2);

    output(roots, x1, x2);
}

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
        return 1;
    }

    else if (iszero(b) && !iszero(c))
        return 0;
    else
        return 4;
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

                return 2;
            }

            else if (iszero(discr))
            {
                *x1 = -b / (2 * a);

                return 1;
            }

            else
                return 0;
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
        case 1:
            printf("Equation has 1 solution: x = %lf\n", x1);
            break;
        case 2:
            printf("Equation has 2 solutions: x1 = %lf and x2 = %lf\n", x1, x2);
            break;
        case 0:
            printf("Equation has no real solutions\n");
            break;
        case 4:
            printf("Equation has infinite number of solutions\n");
            break;
        default:
            break;
    }
}
