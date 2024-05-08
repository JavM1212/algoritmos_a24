#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void radix_sort (int64_t* A, int64_t n);
void counting_sort(int64_t* A, int64_t n, int64_t k);
int64_t get_max(int64_t* A, int64_t n);

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

  radix_sort(arr_to_order, size);

  for (int64_t i = 0; i < size; i++) { 
    fprintf(stdout, "A[%" PRId64 "]: %" PRId64 "\n", i, arr_to_order[i]);
  }
}

void radix_sort(int64_t* A, int64_t n) {
  int64_t max = get_max(A, n);  

  for (int64_t k = 1; max / k > 0; k *= 10) {
    counting_sort(A, n, k);
  }
}

void counting_sort(int64_t* A, int64_t n, int64_t k) {
  int64_t* B = (int64_t*) calloc(n + 1, sizeof(int64_t));

  int64_t max = (A[0] / k) % 10;
  for (int64_t i = 1; i < n; i++) {
    if (((A[i] / k) % 10) > max)
      max = A[i];
  }
  int64_t* C = (int64_t*) calloc(max + 1, sizeof(int64_t));

  for (int64_t i = 0; i < max; ++i) {
    C[i] = 0;
  }

  for (int64_t j = 0; j < n; j++) {
    C[(A[j] / k) % 10]++;
  }
    
  for (int64_t i = 1; i < 10; i++) {
    C[i] += C[i - 1];
  }

  for (int64_t j = n - 1; j >= 0; j--) {
    B[C[(A[j] / k) % 10] - 1] = A[j];
    C[(A[j] / k) % 10]--;
  }

  for (int64_t i = 0; i < n; i++)
    A[i] = B[i];
}

int64_t get_max(int64_t* array, int64_t n) {
  int64_t max = array[0];
  for (int64_t i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
