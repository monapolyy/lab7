#include <stdio.h>

// Function for Bubble Sort and count swaps
void bubbleSort(int arr[], int n, int swapCount[]) {
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount[arr[j]]++;
                swapCount[arr[j + 1]]++;
                totalSwaps++;
            }
        }
    }
    printf("Total swaps (Bubble Sort): %d\n", totalSwaps);
}

// Selection Sort and count swaps
void selectionSort(int arr[], int n, int swapCount[]) {
    int i, j, minIndex, temp, totalSwaps = 0;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCount[arr[i]]++;
            swapCount[arr[minIndex]]++;
            totalSwaps++;
        }
    }
    printf("Total swaps (Selection Sort): %d\n", totalSwaps);
}

int main() {
    int array1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int array2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swapCount1[100] = { 0 }, swapCount2[100] = { 0 };

    printf("Array 1:\n");
    bubbleSort(array1, n1, swapCount1);
    for (int i = 0; i < 100; i++) {
        if (swapCount1[i] > 0) {
            printf("%d: %d\n", i, swapCount1[i]);
        }
    }

    printf("\nArray 2:\n");
    selectionSort(array2, n2, swapCount2);
    for (int i = 0; i < 100; i++) {
        if (swapCount2[i] > 0) {
            printf("%d: %d\n", i, swapCount2[i]);
        }
    }

    return 0;
}