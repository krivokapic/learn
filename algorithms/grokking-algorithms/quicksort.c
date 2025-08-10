#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int sumRec(int *arr, size_t arrLen)
{ 
  if(arrLen == 1)
    return arr[0];
  else
    return arr[0] + sumRec(arr+1, arrLen-1);
}

static int countArr(int *arr, size_t arrLen)
{ 
  if(arrLen == 1)
    return 1;
  else
    return 1 + countArr(arr+1, arrLen-1);
}

static int maxArr(int *arr, size_t arrLen)
{ 
  int max = arr[0];
  if (arrLen > 1 && maxArr(arr+1, arrLen-1) > max)
    max = maxArr(arr+1, arrLen-1);

  return max;
}

static size_t countPositiveValues(int *arr, size_t arrLen){
  size_t count = 0;
  int i;

  for(i = 0; i < arrLen; i++){
    if(arr[i] > 0)
      count+=1;
  }

  return count;
}

static int quicksort(int *arr, size_t arrLen){
  if(arrLen < 2){
    printf("arrLen: %ld, arr: %d\n", arrLen, arrLen == 0 ? 0 : *arr);
    return arrLen == 0 ? 0 : *arr;
  }
  else{
    int arrLenWithoutPivot = arrLen-1;
    int less[arrLenWithoutPivot] = {}, greater[arrLenWithoutPivot] = {}, i;
    int pivot = arr[0];
    for(i = 1; i < arrLen; i++){
      int value = arr[i];
      //printf("pivot %d, value: %d, greater[0]: %d\n", pivot, value, greater[0]);
      if (value > pivot){
        //printf("value: %d\n", value);
        greater[i-1] = value;
      }
      else 
        less[i-1] = value;
    }

    size_t lessArrLen = countPositiveValues(less, arrLenWithoutPivot);
    size_t greaterArrLen = countPositiveValues(greater, arrLenWithoutPivot);
    printf("pivot: %d, lessArrLen: %ld, greaterArrLen: %ld\n", pivot, lessArrLen, greaterArrLen);
    return quicksort(less, lessArrLen) + pivot + quicksort(greater, greaterArrLen);
  }
}

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(int *arr, size_t arrLen){
    if(arrLen < 2)
        return;
    int temp;
    int shift = arrLen - 1; 
    int mid = arrLen / 2;
    for(int i=0; i < mid; i++){
       temp = arr[i];
       arr[i] = arr[i+shift];
       arr[i+shift] = temp;
       shift-=2;
    }
}

int main(int argc, char *argv[])
{
  int arr[] = {1,2,4,5};
  int test[10] = {};
  size_t arrLen = sizeof(arr) / sizeof(arr[0]);
  size_t arrLenTest = sizeof(test) / sizeof(test[0]);
  // printf("sum of %d, %d, %d, %d is %d\n", 10,5,1,3, sumRec(arr, arrLen));
  //printf("count of items in arr: %d\n", countArr(arr, arrLen));
  //printf("max of %d, %d, %d, %d is %d\n", 10,5,1,3, maxArr(arr, arrLen));
  //for(int i=0;i < arrLen; i++){
  //  printf("%d, ", arr[i]);
  //}
  //printf("\n");
  //printf("arrLenTest: %ld\n", arrLenTest);
  //for(int i=0;i < arrLenTest; i++){
  //  printf("%d, ", test[i]);
  //}
  //printf("\n");
  //printf("quicksort: %d\n", quicksort(arr, arrLen));
  //int a = 5;
  //int b = 10;
  //printf("a: %p -> %d\nb: %p -> %d\n", &a, a, &b, b);
  //swap(&a,&b);
  //printf("after swap\n");
  //printf("a: %p -> %d\nb: %p -> %d\n", &a, a, &b, b);
  int arr2[20] = {};
  srand(time(NULL)); // use current time as seed for random generator
  for(int i=0; i < 20; i++){
      arr2[i] = rand();
  }
  
  arrLen = sizeof(arr2) / sizeof(arr2[0]);
  for(int i=0; i < arrLen; i++){
      printf("%p -> %d\n",&arr2[i], arr2[i]);
  }
  printf("-------\n");
  printf("after reverse:\n");
  printf("-------\n");
  reverse(arr2, arrLen);
  for(int i=0; i < arrLen; i++){
      printf("%p -> %d\n",&arr2[i], arr2[i]);
  }
  return 0;
}
