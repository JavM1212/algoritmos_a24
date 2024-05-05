#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void quicksort (int64_t* A, int64_t p, int64_t r);
int64_t partition(int64_t* A, int64_t p, int64_t r);
void exchange (int64_t* a, int64_t* b);

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

  quicksort(arr_to_order, 0, size);

  for (int64_t i = 0; i < size; i++) { 
    fprintf(stdout, "A[%" PRId64 "]: %" PRId64 "\n", i, arr_to_order[i]);
  }
}

void quicksort (int64_t* A, int64_t p, int64_t r) {
  if (p < r) {
    int64_t q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

int64_t partition(int64_t* A, int64_t p, int64_t r) {
  int64_t x = A[r];
  int64_t i = p - 1;
  
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i = i + 1;
      exchange(A + i, A + j);
    }
  }
  exchange(A + i + 1, A + r);

  return i + 1;
}

void exchange (int64_t* a, int64_t* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
