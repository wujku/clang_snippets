#include <inttypes.h>
#include <stdio.h>
#include <string.h>

struct {
    uint8_t options;
	char value[100];
} Property;

char * bufferPtr = (char*) &Property.value;

const char propertyValue[] = "1@#4%6&8";

int main() {
    // Copy string to "value"
    strcat(bufferPtr, propertyValue);

    // Save value to "options"
    *(bufferPtr - 1) = 45;

    // Print value as string
    printf("%s\n", bufferPtr);
    // Print options as decimal
    printf("%d\n", *(bufferPtr - 1));
    // Print options as char
    printf("%c\n", *(bufferPtr - 1));

    return 0;
}
