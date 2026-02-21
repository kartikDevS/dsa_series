#include <stdio.h>

int binary(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;  // base case: not found
    }

    int mid = low + (high - low) / 2;

    if (target == arr[mid]) {
        return mid;  // return index
    }
    else if (target > arr[mid]) {
        return binary(arr, mid + 1, high, target);
    }
    else {
        return binary(arr, low, mid - 1, target);
    }
}

int main() {
    int arr[20] = {1, 3, 8, 9, 13, 19};
    int target;
    scanf("%d", &target);

    int low = 0;
    int high = 5;  // last index of initialized elements
    int index = binary(arr, low, high, target);

    if (index != -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not found\n");
    }

    return 0;
}