/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
// Constant to check that the string ending char has been provided.
#define INPUT_ENDING_CHAR '#'
// Constants to check that the input char is a letter.
// The values of these constants are the ASCII values for 'A','Z','a','z'.
#define UPPERCASE_LETTER_CHAR_MIN_VALUE 65
#define UPPERCASE_LETTER_CHAR_MAX_VALUE 90
#define LOWERCASE_LETTER_CHAR_MIN_VALUE 97
#define LOWERCASE_LETTER_CHAR_MAX_VALUE 122
#define ASCII_LETTER_DISTANCE 32


/*-------------------------------------------------------------------------
  This program takes as input a letter and a string of chars ending with '#'.
  The program will count the number of times the input letter appears in the
  input string in an uppercase or lowercase form and print it.
 -------------------------------------------------------------------------*/
int main()
{
    // Variable to store the input letter to count.
    char letter;
    // Variable to store the other version of the letter to count (upper or lower).
    char reverse_letter;
    // Variable to store the value of each char read from the user string input.
    char input_letter;
    // Variable to count the number of times the letter appeared in the string.
    int count = 0;
    printf("Enter letter to count:\n");
    scanf("%c", &letter);

    // Checking that the input letter is legal.
    // This block checks if the letter is outside the 65 to 90 range (uppercase letters ASCII values)
    // and also outside the 97 to 122 range (lowercase letters ASCII values)
    if ((letter < UPPERCASE_LETTER_CHAR_MIN_VALUE) ||
        (letter > UPPERCASE_LETTER_CHAR_MAX_VALUE && letter < LOWERCASE_LETTER_CHAR_MIN_VALUE) ||
        (letter > LOWERCASE_LETTER_CHAR_MAX_VALUE))
    {
        // The input letter is illegal, the program will exit.
        return 1;
    }

    if (letter >= UPPERCASE_LETTER_CHAR_MIN_VALUE && letter <= UPPERCASE_LETTER_CHAR_MAX_VALUE)
    {
        // The input letter is uppercase, saving the lowercase version
        // in a variable.
        reverse_letter = letter + ASCII_LETTER_DISTANCE;
    }
    else
    {
        // The input letter is lowercase, saving the uppercase version
        // in a variable.
        reverse_letter = letter - ASCII_LETTER_DISTANCE;
    }

    printf("Enter the char sequence:\n");
    scanf("%c", &input_letter);
    while (input_letter != INPUT_ENDING_CHAR)
    {
        if (input_letter == letter || input_letter == reverse_letter)
        {
            // The input letter is the same as the one we want to count.
            count++;
        }
        scanf("%c", &input_letter);
    }

    printf("The letter appeared %d times\n", count);

    return 0;
}
