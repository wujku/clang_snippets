#include <inttypes.h>
#include <stdio.h>

/*
1. Ćwiczenie z Little Endian
https://www.youtube.com/watch?v=75fkLOB3omY

Wariant I  – Liczba = 513 (BA 0201) Little Endian
Wariant II – Liczba = 258 (AB 0102) Big Endian

Wariant I  – Liczba = 513 RAM [0102] Little Endian
Wariant II – Liczba = 258 RAM [0201] Big Endian

Little Endian           Big Endian
0x0201       | RAM  |       0x0201
   | |       |      |          | |
   | +----01 | adr0 | 02 ------+ |
   +------02 | adr1 | 01 --------+
*/

uint16_t tab1[] = { 8, 513, 734, 612,  87 };
// uint16_t tab1[] = { 0x0008,  0x0201, 0x02DE, 0x0264, 0x0057 };
// Little Endian RAM {  08 00,   01 02,  DE 02,  64 02,  57 00 };

uint8_t  tab2[] = { 7,  99,   1,   2, 113 };
// uint8_t tab2[] = { 0x7, 0x63, 0x01, 0x02, 0x71 };

// Rzutowanie tablicy 2 bajtowej na wskaźnik 1 bajtowy
uint8_t  * wsk1 = (uint8_t*)  tab1;

// Rzutowanie tablicy 1 bajtowej na wskaźnik 2 bajtowy
uint16_t * wsk2 = (uint16_t*) tab2;

// 2 bajty                    (0x0201)
// 2 bajty – Little Endian RAM (01 02)
uint16_t z = 513;

// Rzutowanie liczby 2 bajtowej na wskaźnik 1 bajtowy
// (Mozliwość wyświetlenia osobno kazdego z bajtow)
uint8_t * zptr = (uint8_t*) &z;

int main() {
    // 1 i 2 bajt:   8 (0x0008) - zapis za pomocą dwoch bajtow
    // 3 i 4 bajt: 513 (0x0201) - zapis za pomocą dwoch bajtow
    wsk1 += 3; // przejście na drugi bajt liczby 513: Little Endian {01 02 <--}
    
    // 2 pierwsze bajty: 7 i 99 (0x7,  0x63)
    // 2 kolejne bajty:  1 i  2 (0x01, 0x02)
    wsk2 += 1; // przejście na kolejną liczbę 2 bajtową: Little Endian {01 02}

    // Przypisujemy zawartość wskaźnika do zmiennej
    int a = *wsk1; //   2
    int b = *wsk2; // 513

    printf("a: %d, b: %d\n\n", a, b);

    // Przesunięcie wskaźnika na 2 bajt
    zptr += 1;

    printf("z: %d\n\n", *zptr);

    return 0;
}
