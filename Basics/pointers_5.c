#include <inttypes.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    uint8_t options;
    char value[100];
} Property;

typedef void (*D_STR)(char *);
typedef void (*D_VOID)(void);
typedef void (*D_NUM)(uint8_t);

D_NUM function_pointers[3];

Property ConfigProperty;

void *bufferPtr = &ConfigProperty;

void print_string(char *str)
{
    printf("%s\n", str);
}

void print_bold(char *str)
{
    printf("**%s**\n", str);
}

void print_example(void)
{
    print_string("~~Example text~~");
}

void print_number(uint8_t number)
{
    printf("%d\n", number);
}

void print_square_of_number(uint8_t number)
{
    print_number(number * number);
}

void print_negation(uint8_t number)
{
    print_number(-number);
}

void display(uint8_t num, void *callback, void *data)
{
    if (!num)
    {
        // Callback to function with string argument
        D_STR pf = callback;
        
        pf(data);
    }
    else if (1 == num)
    {
        // Callback to void function
        D_VOID pf = callback;
        
        pf();
    }
    else if (2 == num)
    {
        // Pointer to Property struct
        Property *structPtr = data;
        // Callback to function with number argument
        D_NUM pf = callback;

        // Pass number value
        pf(structPtr->options);
    }
    else if (3 == num)
    {
        Property *structPtr = data;
        D_STR pf = callback;
        
        // Pass string value
        pf(structPtr->value);
    }
}

int main()
{
    int value = 3;

    strcat(ConfigProperty.value, "Text");

    // Use function as callback with string data
    display(0, print_bold, "Bold text");

    // Use function as callback with null argument
    display(1, print_example, NULL);

    // Save value to "options"
    ConfigProperty.options = 8;

    // Set functions to pointers
    function_pointers[0] = print_number;
    function_pointers[1] = print_square_of_number;
    function_pointers[2] = print_negation;

    for (uint8_t x; x < 3; x++)
    {
        // Use pointer to function from array to print number in few transformations
        display(2, function_pointers[x], bufferPtr);
    }

    // Use function as callback with struct data
    display(3, print_string, bufferPtr);

    return 0;
}
