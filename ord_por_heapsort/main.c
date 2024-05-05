#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void heapsort(int64_t* A, int64_t n);
void max_heapify(int64_t* A, int64_t n, int64_t i);
void build_max_heap(int64_t* A, int64_t n);
int64_t left(int64_t i);
int64_t right(int64_t r);
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

  heapsort(arr_to_order, size);

  for (int64_t i = 0; i < size; i++) { 
    fprintf(stdout, "A[%" PRId64 "]: %" PRId64 "\n", i, arr_to_order[i]);
  }
}

void heapsort(int64_t* A, int64_t n) {
  build_max_heap(A, n);

  for (int i = n - 1; i >= 0; i--) {
    exchange(&A[0], &A[i]);
    max_heapify(A, i, 0);
  }
}

void max_heapify(int64_t* A, int64_t n, int64_t i) {
  int64_t l = left(i);
  int64_t r = right(i);
  int64_t largest = i;

  if (l < n && A[l] > A[largest]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r < n && A[r] > A[largest]) {
    largest = r;
  }
  if (largest != i) {
    exchange(A + i, A + largest);
    max_heapify(A, n, largest);
  }

  return;
}

void build_max_heap(int64_t* A, int64_t n) {
  for (int64_t i = (n / 2) - 1; i >= 0; i--) {
    max_heapify(A, n, i);
  }
}

int64_t left(int64_t i) {
  return 2 * i + 1;
}

int64_t right(int64_t i) {
  return (2 * i) + 2;
}

void exchange (int64_t* a, int64_t* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
