#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, i;
        scanf("%d", &n);
        int arr[n], newarr[n];
        int total = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            total += arr[i];
        }

        for (i = 0; i < n; i++) {
            newarr[i] = total - arr[i];
        }

        for (i = 0; i < n; i++) {
            printf("%d ", newarr[i]);
        }
        printf("\n");
    }

    return 0;
}