#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


void merge (int64_t* A, int64_t p, int64_t q, int64_t r);
void mergeSort (int64_t* A, int64_t p, int64_t r);

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


  mergeSort(arr_to_order, 0, size - 1);

  for (int64_t i = 0; i < size; i++) { 
    fprintf(stdout, "A[%" PRId64 "]: %" PRId64 "\n", i, arr_to_order[i]);
  }
}

void mergeSort (int64_t* A, int64_t p, int64_t r) {
  if (p >= r) { 
    return;
  }
  int q = (p + r) / 2; 

  mergeSort(A, p, q); 
  mergeSort(A, q + 1, r); 
  merge(A, p, q, r);  
}

void merge (int64_t* A, int64_t p, int64_t q, int64_t r) {
  int nl = q - p + 1; 
  int nr = r - q; 

  int L[nl], R[nr]; 

  for (int i = 0; i < nl; i++) 
    L[i] = A[p + i]; 
  for (int j = 0; j < nr; j++) 
    R[j] = A[q + j + 1]; 

  int i = 0; 
  int j = 0; 
  int k = p; 

  while (i < nl && j < nr) { 
    if (L[i] <= R[j]) { 
      A[k] = L[i]; 
      i++; 
    } else { 
      A[k] = R[j]; 
      j++; 
    } 
    k++; 
  } 

  while (i < nl) { 
    A[k] = L[i]; 
    i++; 
    k++; 
  } 

  while (j < nr) { 
    A[k] = R[j]; 
    j++; 
    k++; 
  } 
}

