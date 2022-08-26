#include <stdio.h>
#include "header.h"

int main(int argc, char* argv[])
{
    double x1 = 0, x2 = 0;
    if (argc == 4)
    {
        solve_square_equation(argv[1], argv[2], argv[3], &x1, &x2);
    }
}
