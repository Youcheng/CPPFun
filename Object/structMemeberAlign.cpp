#include <stdio.h>

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
typedef struct structa_tag
{
    char        c;
    short int   s;
} structa_t;

// structure B
typedef struct structb_tag
{
    short int   s;
    char        c;
    int         i;
} structb_t;

// structure C
typedef struct structc_tag
{
    char        c;
    double      d;
    int         s;
} structc_t;

// structure D
typedef struct structd_tag
{
    double      d;
    int         s;
    char        c;
} structd_t;

int main()
{
    printf("sizeof(structa_t) = %d , alignof(structa_t) = %d\n", sizeof(structa_t), alignof(structa_t));
    printf("sizeof(structb_t) = %d , alignof(structb_t) = %d\n", sizeof(structb_t), alignof(structb_t));
    printf("sizeof(structc_t) = %d , alignof(structc_t) = %d\n", sizeof(structc_t), alignof(structc_t));
    printf("sizeof(structd_t) = %d , alignof(structd_t) = %d\n", sizeof(structd_t), alignof(structd_t));

    /*
     * sizeof(structa_t) = 4 , alignof(structa_t) = 2
     * sizeof(structb_t) = 8 , alignof(structb_t) = 4
     * sizeof(structc_t) = 24 , alignof(structc_t) = 8
     * sizeof(structd_t) = 16 , alignof(structd_t) = 8
     */

    return 0;
}