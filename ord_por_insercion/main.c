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
  /// 1. [2, 5, 7, 10, 1]
  /// 2. [2, 5, 7, 10, 1]
  /// 3. [2, 5, 7, 10, 1]
  /// 4. [1, 2, 5, 7, 10]

  int64_t key = 0;
  int64_t j = 0;
  for (int64_t i = 1; i < size; i++) {
    key = arr_to_order[i];
    j = i - 1;
    while (j >= 0 && arr_to_order[j] > key) {
      arr_to_order[j + 1] = arr_to_order[j];
      j = j - 1;
    }
    arr_to_order[j + 1] = key;
  }

  for (int64_t i = 0; i < size; i++) { 
    fprintf(stdout, "A[%" PRId64 "]: %" PRId64 "\n", i, arr_to_order[i]);
  }
}


