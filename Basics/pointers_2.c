#include <inttypes.h>
#include <stdio.h>
#include <string.h>

uint64_t number = 0x4b616d696c;
uint8_t * ptr = (uint8_t*) &number;
char * chr = (char*) &number;

uint64_t reverse_number = 0;
char * reverse_chr = (char*) &reverse_number;

int main() {
    printf("DEC    | %d, %d, %d, %d, %d\n\n", ptr[4], ptr[3], ptr[2], ptr[1], ptr[0]);
    printf("HEX    | %X, %X, %X, %X, %X\n\n", ptr[4], ptr[3], ptr[2], ptr[1], ptr[0]);
    printf("CHAR   | %c, %c, %c, %c, %c\n\n", chr[4], chr[3], chr[2], chr[1], chr[0]);

    // Reverse a integer
    int length = strlen(chr) - 1;
    for(uint8_t x = 0; chr[x] != '\0'; x++) {
        reverse_chr[length - x] = chr[x];
    }

    printf("STRING | %s\n\n", reverse_chr);

    return 0;
}
