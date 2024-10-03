#include <stdio.h>
#include <string.h>

#define FLAG_LENGTH 27

void decrypt_flag(char* key) {
    char enc_flag[] = {21, 25, 17, 84, 9, 27, 2, 7, 67, 93, 19, 44, 68, 30, 108, 2, 31, 7, 10, 28, 108, 7, 66, 18, 24, 71, 15};
    for (int i = 0; i < FLAG_LENGTH; i++) {
        enc_flag[i] ^= key[i % strlen(key)];
    }
    printf("Congratulations! The flag is: %s\n", enc_flag);
}

int main() {
    char key[] = "sup3rs3cr3t";
    char password[16];

    printf("Enter the password: ");
    gets(password);

    if (strcmp(password, "1337h4x0r") == 0) {
        decrypt_flag(key);
        
    } else {
        printf("Wrong password. Try again.\n");
    }

    return 0;
}
