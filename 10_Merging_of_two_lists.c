#include <stdio.h>

int main() {
    int A[] = {1, 4, 7, 10, 12};
    int B[] = {2, 3, 6, 11};
    int n = 5, m = 4;
    int C[n + m];
    int i = 0, j = 0, k = 0;

    // Merge step 🧠
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements (if any)
    while (i < n) {
        C[k] = A[i];
        i++;
        k++;
    }

    while (j < m) {
        C[k] = B[j];
        j++;
        k++;
    }

    // Display result
    printf("Merged sorted array: ");
    for (int x = 0; x < n + m; x++) {
        printf("%d ", C[x]);
    }
    printf("\n");

    return 0;
}
