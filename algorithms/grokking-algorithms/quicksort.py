def sumRecursion(values):
    if len(values) == 1:
        return values[0]
    else:
        return values[0] + sumRecursion(values[1:])

def countArr(values):
    if len(values) == 1:
        return 1
    else:
        return 1 + countArr(values[1:])

def maxValue(values):
    max = values[0]
    if len(values) > 1 and maxValue(values[1:]) > max:
        max = maxValue(values[1:])
    return max

def quicksort(array):
    if len(array) < 2:
        return array
    else:
        #pivot = array[0]
        pivot = array[len(array) // 2 ]
        less = [i for i in [num for num in array if num != pivot] if i <= pivot]
        greater = [i for i in array if i > pivot]

        return quicksort(less) + [pivot] + quicksort(greater)

def main():
    print(f"sumRecursive: {sumRecursion([1,2,3,4])}")
    print(f"countArr: {countArr([1,2,3,4])}")
    print(f"maxValue: {maxValue([5,10,3,4])}")
    print(f"quicksort: {quicksort([1,55,34,10,5,2,3])}")

if __name__ == "__main__":
    main()
