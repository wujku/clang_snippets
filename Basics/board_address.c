#include <stdio.h>

u_int8_t address;

#define DIP_1 1
#define DIP_2 0
#define DIP_3 0

int main() {
    // Get address from dip switch
    if (DIP_1) {
        // 0bxxxxxxx1
        address |= (1 << 0);        
    }

    if (DIP_2) {
        // 0bxxxxxx1x
        address |= (1 << 1);        
    }

    if (DIP_3) {
        // 0bxxxxx1xx
        address |= (1 << 2);        
    }

    printf("Address is: %d, %x\n", address, address);

    return 0;
}