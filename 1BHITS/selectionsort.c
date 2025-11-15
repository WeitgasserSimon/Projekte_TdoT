#include <stdio.h>

void selection_sort(int arr[], int n) {
  int i, j, min_idx;
  
  for (i = 0; i < n-1; i++) {
    // Finde das kleinste Element in unsortiertem Array
    min_idx = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    // Tausche das gefundene kleinste Element mit dem ersten Element
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i;
  
  printf("Unsortiertes Array: \n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  selection_sort(arr, n);
  
  printf("\nSortiertes Array: \n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}

