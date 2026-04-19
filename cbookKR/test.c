#include <stdio.h>

#define MAX 10

void scale(int *a, int n)
{
    *a *= n;
}

int vladimir = 52;
int main(void)
{
    int in_main1 = 42;
    int in_main2 = 32;
    scale(&in_main1, 2);
    printf("px %d\n", in_main1);
}
