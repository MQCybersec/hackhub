#include <stdio.h>
#include <stdlib.h>

void vuln() {
    char buffer[32];
    printf("Enter your name: ");
    gets(buffer);
    printf("Hello, %s!\n", buffer);
}

void win() {
    printf("flag{pr3tty_b4s1c_if_y0u_ask_m3}\n");
}

void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

int main() {
    setup();

    char* random_string = malloc(8);
    snprintf(random_string, 8, "%06x", rand() & 0xffffff);
    printf("Random String: %s\n", random_string);

    vuln();

    free(random_string);
    return 0;
}
