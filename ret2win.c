#include <stdio.h>

void flag() {
    printf("flag{h0w_d1d_w3_g3t_here?}\n");
}

void foo() {
    char buffer[16];

    printf("Input> \n");
    scanf("%s", buffer);
    printf("Nice try, %s\n", buffer);    
}

int main() {
    foo();
    return 0;
}




