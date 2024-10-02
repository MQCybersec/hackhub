#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_random_string(int length) {
    char* str = malloc(length + 1);
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length] = '\0';
    return str;
}

void vuln() {
    char buffer[80];
    printf("Enter your name: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Hello, %s!\n", buffer);
}

void win() {
    printf("flag{G1ve_us_a_ch33z3_w1th_n0th1n}\n");
}

void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

void obfuscate(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] ^= 0x42;
    }
}

int main() {
    setup();

    srand(time(NULL));
    char* random_string = generate_random_string(8);
    obfuscate(random_string);
    printf("Obfuscated string: %s\n", random_string);

    vuln();

    obfuscate(random_string);
    if (strcmp(random_string, "hackhub123!") == 0) {
        win();
    }

    free(random_string);
    return 0;
}
