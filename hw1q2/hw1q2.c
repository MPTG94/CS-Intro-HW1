/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

// Constant to check that the string ending char has been provided.
#define INPUT_ENDING_CHAR '#'
// Constants to check that the input char is a letter.
#define UPPERCASE_LETTER_CHAR_MIN_VALUE 'A'
#define UPPERCASE_LETTER_CHAR_MAX_VALUE 'Z'
#define LOWERCASE_LETTER_CHAR_MIN_VALUE 'a'
#define LOWERCASE_LETTER_CHAR_MAX_VALUE 'z'


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
    if (scanf(" %c", &letter) != 1)
    {
        return 0;
    }

    // Checking that the input letter is legal.
    // This block checks if the letter is outside the 'A' to 'Z' range
    // and also outside the 'a' to 'z' range.
    if ((letter < UPPERCASE_LETTER_CHAR_MIN_VALUE) ||
            (letter > UPPERCASE_LETTER_CHAR_MAX_VALUE && letter < LOWERCASE_LETTER_CHAR_MIN_VALUE) ||
            (letter > LOWERCASE_LETTER_CHAR_MAX_VALUE))
    {
        // The input letter is illegal, the program will exit.
        return 0;
    }

    if (letter >= UPPERCASE_LETTER_CHAR_MIN_VALUE && letter <= UPPERCASE_LETTER_CHAR_MAX_VALUE)
    {
        // The input letter is uppercase, saving the lowercase version
        // in a variable.
        reverse_letter = letter + (LOWERCASE_LETTER_CHAR_MIN_VALUE - UPPERCASE_LETTER_CHAR_MIN_VALUE);
    }
    else
    {
        // The input letter is lowercase, saving the uppercase version
        // in a variable.
        reverse_letter = letter - (LOWERCASE_LETTER_CHAR_MIN_VALUE - UPPERCASE_LETTER_CHAR_MIN_VALUE);
    }

    printf("Enter the char sequence:\n");
    scanf(" %c", &input_letter);
    while (input_letter != INPUT_ENDING_CHAR)
    {
        if (input_letter == letter || input_letter == reverse_letter)
        {
            // The input letter is the same as the one we want to count.
            count++;
        }
        scanf(" %c", &input_letter);
    }

    printf("The letter appeared %d times\n", count);

    return 0;
}
