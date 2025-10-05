#include <stdio.h>


char strA[80] = "Hello, World!";
char strB[80] = "12345678901234567890123456789012345678901234567890";
char strC[30];
int xs[] = {1,2,3,4,5};
int ys[5];

// parameters are pointers
static char *mystrcpy(char *dest, char *src)
{
    char *p = dest;
    while (*src)
    {
        *p++ = *src++;
    }
    *p = '\0';
    return dest;
}
// parameters are arrays
static char *mystrcpy2(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static int *int_copy(int *dest, int *src, int n)
{
    int *p = dest;
    while (n-- > 0)
        *p++ = *src++;

    return dest;
}

static int sum(int a, int b){
    return a + b;
}

int main(void)
{

    char buff[90];
    printf("buff address: %p\nbuff[0] = %d\n", &buff, buff[0]);
    mystrcpy2(strB, strA);
    puts(strB);
    // puts(strB);
    // mystrcpy(strC, strB);
    // puts(strC);

    //int_copy(ys, xs, 4);
    //size_t sizey = sizeof(ys) / sizeof(ys[0]);
    //size_t sizex = sizeof(xs) / sizeof(xs[0]);
    //printf("size y = %ld, size x = %ld\n", sizey, sizex);
    //for (size_t i = 0; i < sizey; i++)
    //{
    //    printf("ys[%ld] = %d\n", i, ys[i]);
    //}
    
    //puts(strA);
    //pA = strA;
    //puts(pA);
    //pB = strB;
    //putchar('\n');
    //while (*pA != '\0')
    //{
    //    *pB++ = *pA++;
    //}
    //*pB = '\0';
    //puts(strB);
    return 0;
}
