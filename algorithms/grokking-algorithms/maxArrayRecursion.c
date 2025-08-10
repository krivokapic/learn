#include <stdio.h>

static int maxArr(int *arr, size_t arrLen)
{ 
  int max = arr[0];
  int c;
  if (arrLen > 1 && (c = maxArr(arr+1, arrLen-1)) > max)
    max = c;

  return max;
}

int main(int argc, char *argv[])
{
  int arr[4] = {10,50,1,3};
  size_t arrLen = sizeof(arr) / sizeof(arr[0]);
  int max = maxArr(arr, arrLen);
  printf("max of %d, %d, %d, %d is %d\n", 10,50,1,3, max);
  return 0;
}
