#ifndef HEADER_H
#define HEADER_H

#define EPSILON 1e-10

//!--------------------------------
//! @brief Used for colorizing command line's text
//!--------------------------------
enum Colors
{
    WHITE = 1, ///<Inficating white color
    GREEN = 2, ///<indicating green color
    RED   = 3, ///<Indicating red color
};

//!--------------------------------
//! @brief Used for input of coefficients
//! @param[in] a Coefficient for input
//! @return Coefficient for later using
//!--------------------------------
double coeff();

//!--------------------------------
//! @brief Solving linear equations
//! @param[in] b Coeficcient of x in the equation
//! @param[in] c Free term of the equation
//! @param[out] x1 Root of the equation
//! @return Number of roots of the equation
//!--------------------------------
int solve_linear_equation(const double b, const double c, double* const x1);

//!--------------------------------
//! @brief Solving square equations
//! @param[in] a Cofficient of x^2 in the equation
//! @param[in] b Cofficient of x in the equation
//! @param[in] c Free term of the equation
//! @param[out] x1 Firt, lesser root of the equation
//! @param[out] x2 Second, bigger root of the equation
//! @return Number of roots
//!--------------------------------
int solve_square_equation(const double a, const double b, const double c, double* const x1, double* const x2);

//!--------------------------------
//! @brief Used for comparing double numbers with 0
//! @param[in] n Number to compare
//! @return True or False, depending on the number
//!--------------------------------
bool iszero (const double n);

//!--------------------------------
//! @brief Used for output, showing number of roots and roots themselves
//! @param[in] roots Number of roots of the equation
//! @param[in] x1 First, lesser root of the equation
//! @param[in] x2 Second, bigger root of the equation
//! @return True or False, depending on the number
//!--------------------------------
void output(const int roots, const double x1, const double x2);

//!--------------------------------
//! @brief Used for comparing two double numbers
//! @param[in] a First number to compare
//! @param[in] b Second number to compare
//! @return True or False, depending on numbers
//!--------------------------------
bool compare(const double a, const double b);

//!--------------------------------
//! @brief Used for chaging colore of command line's text
//! @param[in] color Color, which will be used for command line
//!--------------------------------
void SetColor(enum Colors color);

#endif //HEADER_H
