#include <stdio.h>
#include <math.h>

int main(void)
{

    double a = 0, b = 0, c = 0, d = 0, x1 = 0, x2 = 0;
    printf("This program will solve quadratic equation with standard form of ax^2 + bx + c = 0\n");
    printf("Enter the coefficients for the equation:\n");
    printf("For x^2: ");
    scanf("%lf", &a);
    printf("For x: ");
    scanf("%lf", &b);
    printf("Free term: ");
    scanf("%lf", &c);

    if (a == 0)
    {
        printf("It's not a quadratic equation, you moron\n");
        printf("This equation has 1 solution: x = %lf", -c/b);
    }

    else
    {
        d = b * b - 4 * a * c;

        if (d > 0)
        {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);

            printf("This equation has 2 solutions:\n");
            printf("x = %lf, x = %lf", x1, x2);
        }

        else if (d == 0.0)
        {
            x1 = -b / (2 * a);

            printf("This equation has 1 solution: x = %lf", x1);
        }

        else
            printf("This equation has no real solutions");
    }

    return 0;
}
