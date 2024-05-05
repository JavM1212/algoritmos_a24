#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main () {
  int64_t size = 5;
  int64_t* arr_to_order = (int64_t*) calloc(size, sizeof(int64_t));
  if (!arr_to_order) {
    return EXIT_FAILURE;
  }
  *(arr_to_order + 0) = 5; *(arr_to_order + 1) = 2; *(arr_to_order + 2) = 7;
  *(arr_to_order + 3) = 10; *(arr_to_order + 4) = 1;

  for (int64_t i = 0; i < size; i++) { 
    fprintf(stdout, "A[%" PRId64 "]: %" PRId64 "\n", i, arr_to_order[i]);
  } fprintf(stdout, "\n\n");

  /// [5, 2, 7, 10, 1]
  /// 1. [1, 2, 7, 10, 5]
  /// 2. [1, 2, 7, 10, 5]
  /// 3. [1, 2, 5, 10, 7]
  /// 4. [1, 2, 5, 7, 10]

  int64_t min = 0;
  int64_t temp = 0;
  for (int64_t i = 0; i < size; i++) {
    min = i;
    for (int64_t j = i + 1; j < size; j++) {
      if (arr_to_order[j] < arr_to_order[min]) {
        min = j;
      }
    }
    temp = arr_to_order[i];
    arr_to_order[i] = arr_to_order[min];
    arr_to_order[min] = temp;
  }

  for (int64_t i = 0; i < size; i++) { 
    fprintf(stdout, "A[%" PRId64 "]: %" PRId64 "\n", i, arr_to_order[i]);
  }
}


