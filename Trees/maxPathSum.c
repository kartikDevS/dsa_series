#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Recursive function to compute max path sum
int maxPathSumUtil(int arr[], int n, int i, int *res) {
    if (i >= n || arr[i] == -1) return INT_MIN; // no node

    // Leaf node
    if ((2*i+1 >= n || arr[2*i+1] == -1) &&
        (2*i+2 >= n || arr[2*i+2] == -1)) {
        return arr[i];
    }

    // Recurse for left and right children
    int ls = maxPathSumUtil(arr, n, 2*i+1, res);
    int rs = maxPathSumUtil(arr, n, 2*i+2, res);

    // If both children exist
    if (ls != INT_MIN && rs != INT_MIN) {
        // Update result if path through this node is greater
        if (ls + rs + arr[i] > *res)
            *res = ls + rs + arr[i];
        // Return max path sum going down one side
        return arr[i] + (ls > rs ? ls : rs);
    }

    // If only one child exists
    return (ls == INT_MIN ? rs : ls) + arr[i];
}

// Wrapper function
int maxPathSum(int arr[], int n) {
    int res = INT_MIN;
    maxPathSumUtil(arr, n, 0, &res);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", maxPathSum(arr, n));
    return 0;
}
