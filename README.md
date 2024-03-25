# Substitution Cipher
A program that puts a phrase or text through a substitution cipher, input by the user through the command line interface.

### Criterion
+ In a file called substition.c, create a program that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.
+ our program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
+ If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
+ If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
+ our program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
+ Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
+ Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
+ After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

### Additional info

This program uses a cs50.h header file, available [here](https://cs50.readthedocs.io/libraries/cs50/c/).
