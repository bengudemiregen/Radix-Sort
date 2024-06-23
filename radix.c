#include <stdio.h>

// Dizinin en büyük elemanını bulma
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Sıralamak için fonksiyon
void Sirala(int arr[], int n, int exp) {
    int output[n]; // Sıralanmış çıktı dizisi
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        Sirala(arr, n, exp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5,150,75,44,12,66,80,59};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Siralanmamis Dizi: \n");
    printArray(arr, n);
    printf("\n\n");

    radixSort(arr, n);

    printf("Radix Sort Kullanilarak Siralanmis Dizi: \n");
    printArray(arr, n);
    return 0;
}