/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
// constant to handle numbers very near zero.
#define ZERO 0.000001


/*-------------------------------------------------------------------------
  This program takes as input the coefficients of a polynomial and returns
  the roots of the polynomial.
  The program knows how to handle polynomials of the 2nd degree.
 -------------------------------------------------------------------------*/
int main()
{
    // Declaring variables to store the values of all polynomials.
    double a;
    double b;
    double c;
    // variable to store the value of the discriminant of the polynomial.
    double discriminant = 0;
    // Variable to store the value of the square root of the discriminant.
    double sqrdiscriminant = 0;
    // variables to store the roots of the polynomial.
    double root1 = 0;
    double root2 = 0;
    printf("Enter the coefficients of a polynomial:\n");
    // Storing input coefficients inside pre-declared variables.
    // The program will exit if invalid input will be provided
    // (for example chars instead of numbers).

    if (scanf("%lf%lf%lf", &a, &b, &c) != 3)
    {
        return 0;
    }

    // Checking the value of the primary coefficient.
    while (a > -ZERO && a < ZERO)
    {
        // Primary coefficient is 0 or very near the value of 0, asking for new
        // input.
        // The program will continue asking for new coefficients until the
        // Primary coefficient is different than 0.
        printf("Enter the coefficients of a polynomial:\n");
        // Storing input coefficients inside pre-declared variables.
        // The program will exit if invalid input will be provided
        // (for example chars instead of numbers).
        if (scanf("%lf%lf%lf", &a, &b, &c) != 3)
        {
            return 0;
        }
    }

    // Calculating the discriminant of the polynomial.
    discriminant = (b*b)-4*(a*c);

    // Checking the value of the discriminant to determine the correct roots
    // printing.
    if (discriminant > 0)
    {
        // The discriminant is larger than 0, meaning there are 2 roots for
        // the input polynomial.

        // Calculating the roots of the polynomial.
        // Calculating the square root of the discriminant
        sqrdiscriminant = sqrt(discriminant);
        // Calculating the roots of the polynomial.
        root1 = (-b + sqrdiscriminant)/(2*a);
        root2 = (-b - sqrdiscriminant)/(2*a);
        // Performing a check to see which root is smaller and print it first.
        if (root1 > root2)
        {
            printf("The roots are %.2f, %.2f\n", root2, root1);
        }
        else
        {
            printf("The roots are %.2f, %.2f\n", root1, root2);
        }
    }
    else if (discriminant > -ZERO && discriminant < ZERO )
    {
        // The discriminant is equal to 0, meaning there is 1 root for the
        // input polynomial.

        // Calculating the root of the polynomial.
        root1 = (-b)/(2*a);
        if (root1 > -ZERO && root1 < ZERO)
        {
            root1 = 0;
        }
        printf("The root is %.2f\n", root1);
    }
    else
    {
        // The discriminant is smaller than 0, meaning there are no roots for
        // the input polynomial.
        printf("There are no roots\n");
    }
    return 0;
}
