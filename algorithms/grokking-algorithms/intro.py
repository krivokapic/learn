import numpy as np
import math

def get_halves(num):
    sum = num
    i = 1
    print(f"{0} {num} start")
    while math.ceil(sum) != 1:
        sum /= 2
        print(f"{i} {math.ceil(sum)}")
        i += 1


def binary_search(arr, item):
    low = 0
    high = len(arr) - 1
    print(f"searching for {item}, in a list of: {arr}")
    while low <= high:
        mid = (low + high) // 2
        guess = arr[mid]
        print(f"low: {low} high: {high} mid: {mid}, guess: {guess}")
        if guess == item:
            return mid
        elif guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None

def binary_search_DC2(arr, item):
    low = 0
    high = len(arr) - 1
    mid = (low + high) // 2
    guess = arr[mid]
    print(f"arr: {arr}, guess: {guess}")
    if item == guess:
        print("found it!")
        return mid
    else:
        print(f"continue searching in {arr[mid+1:] if item > guess else arr[0:mid-1]}...")
        return binary_search_DC2(arr[mid+1:], item) if item > guess else binary_search_DC2(arr[0:mid], item)

    return None

def binary_search_DC(arr, item):
    print("----------")
    print(f"starting search for {item}, in a list of: {arr}")
    if len(arr) == 2:
        print(f"found it!")
        return 0 if arr[0] == item else 1
    else:
        guess, low = 0, 0
        high_total = len(arr) - 1
        high_half = (low + high_total) // 2
        tmp_arr = arr[:high_half+1]
        print(f"searching for {item}, in the lower half: {tmp_arr}")
        while low <= high_half:
            mid = (low + high_half) // 2
            guess = tmp_arr[mid]
            print(f"low: {low} high: {high_half} mid: {mid}, guess: {guess}")
            if guess == item:
                return mid
            elif guess > item:
                high_half = mid - 1
            else:
                low = mid + 1
        if guess == item:
            return guess
        else:
           print("searching upper half..")
           return (high_half+1) + binary_search_DC(arr[high_half+1:], item)

    return None

def main():
    list = [1, 3, 5, 7, 9, 11, 2, 124, 43, 34]


    # print(list[3:])
    #print("binary_search:")
    #print(binary_search(sorted(list), 124))
    #print("=========================")
    #print("binary_search_DC (divide & conquer):")
    #print(binary_search_DC(sorted(list), 124))
    print("binary_search_DC2 (divide & conquer):")
    print(binary_search_DC2(sorted(list), 124))
    # # get_halves(28)


if __name__ == "__main__":
    main()
