#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes for functions.
int inputs(int argc);
int lettercount(string key);
int alphacheck(string key);
int singlechar(string key);
int validatekey(string key);
string cipherupper(string key);
string inputcase(string plain);
string encrypt(string text);
void restorecase(char answerf[]);

// set global variables for all functions to call
int keylength = 0;
string cipher = 0;
string plaintext = 0;
char uplow[] = {0};
string upperplain = 0;
char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char output[] = {0};
char answer[] = {0};
// Global variables to validate key from output of functions
int val_inputs = 0;
int val_count = 0;
int val_alpha = 0;
int val_charcheck = 0;

// Get key using command line argument (int argc, string argv[]).
int main(int argc, string argv[])
{
    inputs(argc);
    lettercount(argv[1]);
    alphacheck(argv[1]);
    singlechar(argv[1]);
    validatekey(argv[1]);
    cipherupper(argv[1]);

    // Get plaintext from user.
    plaintext = get_string("Plaintext: ");

    inputcase(plaintext);
    encrypt(plaintext);
    restorecase(output);

    // return ciphertext
    printf("Ciphertext: %s\n", answer);

}

// Functions outside of main

// Function to check for only one input through CLI
int inputs(int argc)
{
    if (argc == 1 || argc > 2)
        {
            printf("Usage: ./substitution key\n");
            val_inputs = 1;
            return 1;
        }
    return 0;
}

// Function to check length of key is 26 characters
int lettercount(string key)
{
    // Save variable for key length.
    keylength = strlen(key);
        // check to ensure that key is 26 characters
    if ((strlen(key)) != 26)
    {
        val_count = 1;
        return 1;
    }
    return 0;
}

// Function to check all characters are alphabetical
int alphacheck(string key)
{
    int alpha = 0;

    // Loop to check through keylength for alphabetic characters.
    for (int i = 0; i < keylength; i++)
    {
        if (isalpha(key[i]))
            {
                alpha = alpha + 1;
            }
    }
    // If result does not equal 26, add to variable.
    if (alpha < 26)
        {
            val_alpha = 1;
            return 1;
        }
    return 0;
}

// Function to check for no duplicate characters
int singlechar(string key)
{
    // Loop to run through length of key.
    for (int i = 0; i < keylength; i++)
    {
        //Nested loop for checking each char for matching.
        for (int j = i + 1; j < keylength; j++)
        {
            if (key[i] == key[j])
            {
                val_charcheck = 1;
                return 1;
            }
        }
    }
    return 0;
}

// A function to validate the cipher key.
int validatekey(string key)
{
    // Conditional check to ensure all variables meet the critera of being 0.
    if (val_inputs == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (val_count == 1)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (val_alpha == 1)
    {
        printf("Not all characters are alphabetic\n");
        return 1;
    }
    if (val_charcheck == 1)
    {
        printf("Each character can only be used once.\n");
        return 1;
    }
    // Set cipher variable as validated
    cipher = key;
    // printf("Key : %s\n", cipher);
    return 0;
}

// function to convert key to uppercase
string cipherupper(string key)
{
    for (int i = 0; i < keylength; i++)
    {
        key[i] = toupper(key[i]);
    }
    cipher = key;
    return 0;
}

//A function to store a record of plain text case
string inputcase(string plain)
{
    // local variable to record plain text length
    int len = strlen(plain);
    // Loop to run through each character.
    for (int i = 0; i < len; i++)
    {
        // Conditional check to update characrters to a 1 or 0 if uppercase/lowercase.
        if (isalpha(plain[i]))
        {
        if (isupper(plain[i]) == 0)
            {
                uplow[i] = '0';
            }
        else
            {
                uplow[i] = '1';
            }
        }
        if (isalpha(plain[i]) == 0)
        {
            uplow[i] = plain[i];
        }
    }
    return 0;
}

// Function to encrypt cipher and ensure that case, spacing and symbols are replaced.
string encrypt(string text)
{
    int len = strlen(plaintext);
    // Researched character pointers after guidance from CS50 duck when struggling with segmentation fault.
    char *uppertext;
    uppertext = malloc((len + 1) * sizeof(char));
    // convert to uppercase, skip over spaces and characters.
    for (int i = 0; i < len; i++)
    {
        uppertext[i] = toupper(text[i]);
    }
    upperplain = uppertext;

    // use the cipher.
    // loop for number of chars in plain text string.
    for (int i = 0; i < len; i++)
    {
        // printf("upperlain: %s\n", upperplain);
        // a nested loop to compare each char with the cipher.
        for (int j = 0; j < keylength; j++)
        {
            //printf("#");
            if (upperplain[i] == alphabet[j])
            {
                output[i] = cipher[j];
                break;
            }
            // If alphabetical character cannot be found, break so that the value is not over written.
            else
            {
                output[i] = upperplain[i];
            }
        }
    }
    printf("output : %s\n", output);
    return 0;
}

// Function to restore case
void restorecase(char answerf[])
{
    int i;
    int j;
    int len = strlen(answerf);

    for (i = 0, j = 0; i < len; i++, j++)
    {
        if (uplow[j] == 0)
        {
            answer[i] = toupper(answerf[i]);
        }
        else if (uplow[j] == 1)
        {
            answer[i] = tolower(answerf[i]);
        }
        else
        {
            answer[i] = answerf[i];
        }

    }
    answer[i] = '\0';
}

    // return case spacing and characters.
