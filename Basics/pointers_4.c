#include <inttypes.h>
#include <stdio.h>
#include <string.h>

typedef void (*TDISPLAY)(char *, uint8_t);

void display(char* str, uint8_t length) {
    printf("%s (%d)\n", str, length);
}

TDISPLAY dis = display;

int main() {
    char * value = "Test";

    // Use pointer to function
    dis(value, strlen(value));

    return 0;
}
