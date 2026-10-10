#include <stdio.h>

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void quick_sort(int arr[], int lo, int hi) {
    if (hi - lo < 2)
        return;

    int pivot = lo + (hi - lo) / 2;
    swap(arr, pivot, hi - 1);
    pivot = hi - 1;

    int i = lo, j = hi - 2;

    while (i <= j) {
        if (arr[i] < arr[pivot]) {
            i++;
        } else if (arr[j] >= arr[pivot]) {
            j--;
        } else {
            swap(arr, i, j);
        }
    }

    swap(arr, pivot, i);
    pivot = i;

    quick_sort(arr, lo, pivot);
    quick_sort(arr, pivot + 1, hi);
}

void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d%s", arr[i], i + 1 < len ? ", " : "\n");
    }
}

int main() {

    // int arr[] = {2, 5, 6, 2, 3, 5, 10, 4};
    int arr[] = {2, 5, 6, 2};

    int len = sizeof(arr) / sizeof(arr[0]);
    printf("input:\n");
    print_arr(arr, len);
    quick_sort(arr, 0, len);
    printf("output:\n");
    print_arr(arr, len);

    return 0;
}
