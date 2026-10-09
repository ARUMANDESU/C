#include <stdio.h>

/*
 * [3,2,0,1]
 * [3,2], [0,1]
 * [3], [2], [0], [1]
 * [2,3], [0,1]
 * [0,1,2,3]
 */

/*
 * [2,5,6,2,3,5,4]
 * [2,5,6,2], [3,5,4]
 * [2,4], [6,2] [3,5], [4]
 * [2], [4], [6], [2], [3], [5], [4]
 * [2,4], [2,6], [3,5], [4]
 * [2,2,4,6], [3,4,5]
 * [2,2,3,4,4,5,6]
 */

void copy_arr(int src[], int dest[], int lo, int hi) {
    for (; lo < hi; lo++) {
        dest[lo] = src[lo];
    }
}

// merge_sort sorts int array by first dividing arr into unsorted sub-arrays
// then merge this sub-arrays to produce sorted sub-arrays until there only one
// sub-array remaining
void merge_sort(int arr[], int tmp[], int lo, int hi) {
    if (hi - lo < 2)
        return;

    int mid = lo + (hi - lo) / 2;
    merge_sort(arr, tmp, lo, mid);
    merge_sort(arr, tmp, mid, hi);

    int i = lo;
    int j = mid;
    int k = lo;
    while (i < mid && j < hi) {
        tmp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i < mid) {
        tmp[k++] = arr[i++];
    }
    while (j < hi) {
        tmp[k++] = arr[j++];
    }

    copy_arr(tmp, arr, lo, hi);
}

void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d%s", arr[i], i + 1 < len ? ", " : "\n");
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 5, 6, 2, 3, 5, 10, 4};
    // int arr[] = {2, 5, 6, 2};

    int len = sizeof(arr) / sizeof(arr[0]);
    int tmp[len];
    merge_sort(arr, tmp, 0, len);
    print_arr(arr, len);

    return 0;
}
