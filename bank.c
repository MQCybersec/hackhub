#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FLAG_LENGTH 27
#define RANDOM_STRING_LENGTH 6

void generate_random_string(char* str, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length] = '\0';
}

int main() {
    char code[5];
    char flag[] = "flag{1_n33d_a_m3d1c_b4g}";
    char random_string[RANDOM_STRING_LENGTH + 1];

    srand(time(NULL));  // Seed the random number generator with the current time

    // Generate a random 6-digit code
    for (int i = 0; i < 6; i++) {
        code[i] = '0' + rand() % 10;
    }

    // Generate a random string
    generate_random_string(random_string, RANDOM_STRING_LENGTH);

    printf("Welcome to the Bank Vault!\n");
    printf("Enter the 6-digit access code: ");
    char user_code[6];
    gets(user_code);
    
    if (strcmp(user_code, code) == 0) {
        printf("Access granted!\n");
        char user_string[RANDOM_STRING_LENGTH + 1];
        printf("2FA Code: ");
        gets(user_string);

        if (strcmp(user_string, random_string) == 0) {
            printf("Confirmation successful. The flag is: %s\n", flag);
        } else {
            printf("Confirmation failed. Access denied.\n");
        }
    } else {
        printf("Invalid code. Access denied.\n");
    }

    return 0;
}
