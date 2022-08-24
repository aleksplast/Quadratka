#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <conio.h>

double coeff(double a);
int solve_linear_equation(double b, double c, double* x1);
int solve_quadratic_equation(double a, double b, double c, double* x1, double* x2);
bool iszero (double n);
void output(int roots, double x1, double x2);
void square_equation(void);
