#include <stdio.h>
#include <math.h>

static int binarySearch(int *arr, size_t arrLen, int elem){
  int low = 0;
  int high = arrLen - 1;
  printf("----------------\n");
  while(low <= high){
    int mid = (low+high) / 2;
    int guess = *(arr+mid);
    if(guess == elem){
      printf("low: %d, high: %d, mid: %d, guess: %d found it!\n", low, high, mid, guess);
      return guess;
    }
    else if(guess > elem){
      printf("low: %d, high: %d, mid: %d, guess: %d\n", low, high, mid, guess);
      high = mid - 1;
    }
    else{
      printf("low: %d, high: %d, mid: %d, guess: %d\n", low, high, mid, guess);
      low = mid + 1;
    }
  }
  printf("Element %d not found!\n", elem);
  return 1;
}

static void getHalves(int start){
  float sum = start;
  int i = 1;
  printf("0 %d\n", start);
  while(ceil(sum) != 1){
    sum /= 2.0f;
    printf("%d %.0f\n", i, ceil(sum));
    i += 1;
  }
}

int main(int argc, char *argv[])
{
  int array[] = {1,2,3,4,5};
  short arrayLen = sizeof(array) / sizeof(array[0]);
  // for(int i = 0; i < arrayLen; i++){
  //   printf("%p -> %d\n", &array[i], array[i]);
  // }
  //getHalves(100);
  int array2[10] = {1,2,3,4,5,6,7,8,9,10};
  arrayLen = sizeof(array2) / sizeof(array2[0]);
  for(int i = 0; i <= arrayLen; i++){
    int test = binarySearch(array2, arrayLen, i);
  }
  return 0;
}

