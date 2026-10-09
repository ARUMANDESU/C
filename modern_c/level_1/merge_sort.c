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

void copy_arr(int src[], int dest[], int idx, int len) {
  for (int i = 0; idx < len; idx++, i++) {
    dest[idx] = src[i];
  }
}

// merge_sort sorts int array by first deviding arr into unsorted sub-arrays
// then merge this sug-arrays to produce sorted sub-arrays until there only one
// sub-array remaining
void merge_sort(int arr[], int start, int length) {
  if (length < 2)
    return;

  int half = length / 2;
  merge_sort(arr, start, half);
  merge_sort(arr, start + half, length - half);

  int tmp[length];

  int i = start, iend = start + half;
  int j = start + half, jend = start + length;
  int k = 0;
  while (i < iend && j < jend) {
    tmp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
  }
  while (i < iend) {
    tmp[k++] = arr[i++];
  }
  while (j < jend) {
    tmp[k++] = arr[j++];
  }

  copy_arr(tmp, arr, start, start + length);
}

void print_arr(int arr[], int start, int length) {
  for (; start < length; start++) {
    printf("%d, ", arr[start]);
  }
  printf("\n");
}

int main() {
  int arr[] = {2, 5, 6, 2, 3, 5, 10, 4};
  // int arr[] = {2, 5, 6, 2};

  int len = sizeof(arr) / sizeof(arr[0]);
  merge_sort(arr, 0, len);
  print_arr(arr, 0, len);

  return 0;
}
