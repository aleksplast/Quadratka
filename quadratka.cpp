#include <stdio.h>
#include <math.h>

double coeff(double a);
void solve_linear_equation(double b, double c);
void solve_quadratic_equation(double a, double b, double c);

int main(void)
{

    double a = 0, b = 0, c = 0;

    printf("This program will solve quadratic equation with standard form of ax^2 + bx + c = 0\n");

    a = coeff(a);
    b = coeff(b);
    c = coeff(c);

    printf("Your equation: %.2lf * x^2 + %.2lf * x + %.2lf = 0\n", a, b, c);

    if (a == 0)
    {
        solve_linear_equation(b,c);
    }

    else
    {
        solve_quadratic_equation(a,b,c);
    }

    return 0;
}

double coeff(double a)
{
    printf("Enter the coefficient\n");

    if (scanf("%lf", &a) == 1)
        return a;
    else
    {
        fflush(stdin);

        printf("Wrong input, enter a real number\n");

        return coeff(a);
    }
}

void solve_linear_equation(double b, double c)
{
    if (b != 0)
    {
        printf("Solving linear equation\n");
        printf("x = %lf", -c/b);
    }

    else if (b == 0 && c != 0)
        printf("This equation has no real solutions");
    else
        printf("This equation has infinite number of solutions");
}

void solve_quadratic_equation(double a, double b, double c)
{
    double discr = 0, x1 = 0, x2 = 0;

    discr = b * b - 4 * a * c;

        if (discr > 0)
        {
            discr = sqrt(discr);

            x1 = (-b + discr) / (2 * a);
            x2 = (-b - discr) / (2 * a);

            printf("This equation has 2 solutions:\n");
            printf("x = %lf, x = %lf", x1, x2);
        }

        else if (discr == 0.0)
        {
            x1 = -b / (2 * a);

            printf("This equation has 1 solution: x = %lf", x1);
        }

        else
            printf("This equation has no real solutions");
}
