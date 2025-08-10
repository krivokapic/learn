#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv){
  int a = 10;
  char b[] = "vlada";
  int arr[9] = {1};
  // int x[], y[] = {};
  int z;
  size_t size = 1;
  int *p = (int*)malloc(size * sizeof(int));
  // size_t arrLenP = sizeof()
  p[1] = 10;
  size_t arrLen = sizeof(arr) / sizeof(arr[0]);
  printf("Hello world, %s\n", b);
  //printf("x: %p,sizeof(x): %ld\ny: %p,sizeof(y): %ld\nz: %p,sizeof(z): %ld\n", &x, sizeof(x), &y, sizeof(y), &z, sizeof(z));
  printf("dereferencing an empty array: %d\n", arrLen == 0 ? 0 : *arr);
  printf("len of malloc arry p: %ld\np[0] = %d\np[1] = %d\n", sizeof(p) / sizeof(p[0]), p[0], p[1]);
  printf("len of arr: %ld\n", sizeof(arr)/sizeof(arr[0]));
}
