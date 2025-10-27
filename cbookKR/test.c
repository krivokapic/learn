#include <stdio.h>

int *pointer(int a)
{
    int *p = &a;

    return p;
}

int main(void)
{
    int x = 42;
    int *pX = pointer(x);
    printf("px %p\n", pX);
}
