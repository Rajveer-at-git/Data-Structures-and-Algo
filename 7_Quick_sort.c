/*      Algorithm
quickSort(A, low, high):
    if low < high:
        m = partition(A, low, high)
        quickSort(A, low, m - 1)
        quickSort(A, m + 1, high)

partition(A, low, high):
    pivot = A[high]
    i = low - 1
    for j = low to high - 1:
        if A[j] <= pivot:
            i = i + 1
            swap(A[i], A[j])
    swap(A[i + 1], A[high])
    return i + 1

*/  

#include <stdio.h>

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && arr[j] >= pivot)
                j--;
            if (i < j)
                arr[i++] = arr[j];
            while (i < j && arr[i] <= pivot)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = pivot;
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}

int main() {
    int n;
    printf("How many elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}


