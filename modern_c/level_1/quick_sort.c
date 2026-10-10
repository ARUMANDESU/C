#include <stdio.h>

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void print_arr_li_hi(int arr[], int lo, int hi) {
    for (; lo < hi; lo++) {
        printf("%d%s", arr[lo], lo + 1 < hi ? ", " : "\n");
    }
}

void quick_sort(int arr[], int lo, int hi) {
    if (hi - lo < 2)
        return;

    int pivot = lo + (hi - lo) / 2;
    printf("pivot: %d(%d); lo: %d, hi: %d\n", pivot, arr[pivot], lo, hi);
    swap(arr, pivot, hi - 1);
    pivot = hi - 1;

    int i = lo, j = hi - 2;

    while (i <= j) {
        print_arr_li_hi(arr, lo, hi);
        printf("i: %d(%d); j: %d(%d)\n", i, arr[i], j, arr[j]);
        if (arr[i] < arr[pivot]) {
            printf("next i\n");
            i++;
        } else if (arr[j] >= arr[pivot]) {
            printf("next j\n");
            j--;
        } else {
            printf("swap\n");
            swap(arr, i, j);
        }
        print_arr_li_hi(arr, lo, hi);
        printf("i: %d(%d); j: %d(%d)\n", i, arr[i], j, arr[j]);
        printf("\n");
    }

    swap(arr, pivot, i);
    pivot = i;
    printf("pivot: %d(%d)\n", pivot, arr[pivot]);
    printf("\n");

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
