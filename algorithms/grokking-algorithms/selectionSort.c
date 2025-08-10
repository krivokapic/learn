#include <stdio.h>
#include <math.h>
#include <string.h>

static int findSmallest(int *arr, size_t arrayLen){
    int smallest = arr[0];
    int smallestIndex = 0;
    int i;
    for(i = 1; i < arrayLen; i++){
        if(*(arr+i) < smallest){
            smallest = *(arr+i);
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

static int* copyArr(int *arr, int *target, size_t arrLen){
    int i = 0;
    //for(i = 0; i < arrLen; i++){
    //    target[i] = *(arr+i);
    //}
    while(target[i++] = *(arr+i))
        ;

    return target;
}

void removeElement(int *array, int index, int arrLen){
    int i;
    for(i = index; i < arrLen; i++){
        array[i] = array[i+1];
    }
}

static int* selectionSort(int *arr, int *target, size_t arrLen){
    int copiedArr[sizeof(arr)*arrLen];
    memcpy(copiedArr, arr, sizeof(arr[0])*arrLen);
    //copyArr(arr, copiedArr, arrLen);
    int i;
    for(i = 0; arrLen > 0; i++, arrLen--){
        int smallest = findSmallest(copiedArr, arrLen);
        target[i] = *(copiedArr+smallest);
        removeElement(copiedArr, smallest, arrLen);
    }
    return target;
    
}

int main(int argc, char *argv[])
{
    int array[] = {5,3,6,2,10};
    size_t arrLen = sizeof(array) / sizeof(array[0]);
    int sortedArray[arrLen];
    selectionSort(array, sortedArray, arrLen);
    int i;
    printf("Original array:\n");
    for(i = 0; i < arrLen; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Sorted array:\n");
    for(i = 0; i < arrLen; i++){
        printf("%d ", sortedArray[i]);
    }
    printf("\n");

    //int empty[50];
    //int nums[] = {1,2,3,4,5,6,7,8,9,10};
    //size_t arrLen = sizeof(nums) / sizeof(nums[0]);
    //memcpy(empty,nums, sizeof(nums[0])*arrLen);
    //int i;
    //for (i = 0; i < arrLen; i++)
    //{
    //    printf("original: %p -> %d, copied: %p -> %d\n", &nums[i], nums[i], &empty[i], empty[i]);
    //}
    
}