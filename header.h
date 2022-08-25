#include <stdio.h>

#define EPSILON 1e-10

//!--------------------------------
//! @brief Used for input of coefficients
//! @param[in] a Coefficient for input
//! @return Coefficient for later using
//!--------------------------------

double coeff(double a);

//!--------------------------------
//! @brief Solving linear equations
//! @param[in] b Coeficcient of x in the equation
//! @param[in] c Free term of the equation
//! @param[out] x1 Root of the equation
//! @return Number of roots of the equation
//!--------------------------------

int solve_linear_equation(double b, double c, double* x1);

//!--------------------------------
//! @brief Solving square equations
//! @param[in] a Cofficient of x^2 in the equation
//! @param[in] b Cofficient of x in the equation
//! @param[in] c Free term of the equation
//! @param[out] x1 Firt, lesser root of the equation
//! @param[out] x2 Second, bigger root of the equation
//! @return Number of roots
//!--------------------------------

int solve_square_equation(double a, double b, double c, double* x1, double* x2);

//!--------------------------------
//! @brief Used for comparing double numbers with 0
//! @param[in] n Number to compare
//! @return True or False, depending on the number
//!--------------------------------

bool iszero (double n);

//!--------------------------------
//! @brief Used for output, showing number of roots and roots themselves
//! @param[in] roots Number of roots of the equation
//! @param[in] x1 First, lesser root of the equation
//! @param[in] x2 Second, bigger root of the equation
//! @return True or False, depending on the number
//!--------------------------------

void output(int roots, double x1, double x2);

//!--------------------------------
//! @brief Used for comparing two double numbers
//! @param[in] a First number to compare
//! @param[in] b Second number to compare
//! @return True or False, depending on numbers
//!--------------------------------

bool compare(double a, double b);

//!--------------------------------
//! @brief Used for testing of the equations
//! @param[in] a Cofficient of x^2 in the equation
//! @param[in] b Cofficient of x in the equation
//! @param[in] c Free term of the equation
//! @param[in] n_ans Expected number of roots of the equation
//! @param[in] x1_ans Expected lesser root of the equation
//! @param[in] x2_ans Expected bigger root of the equation
//! @return True or False, depending on numbers
//!--------------------------------

void test_equation(double a, double b, double c, int n_ans, double x1_ans, double x2_ans);


