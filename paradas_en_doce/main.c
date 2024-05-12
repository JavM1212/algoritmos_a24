#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int paradasEnDoceItr(int* A, int n);

int main () {
  int n = 9;
  int* A = (int*) calloc(n, sizeof(int));
  if (!A) {
    return EXIT_FAILURE;
  }
  A[0] = 2;
  A[1] = 4;
  A[2] = 6;
  A[3] = 8;
  A[4] = 10;
  A[5] = 12;
  A[6] = 13;
  A[7] = 5;
  A[8] = 7;

  // for (int i = 0; i < n; i++) { 
    // fprintf(stdout, "A[%d]: %d\n", i, A[i]);
  // } fprintf(stdout, "\n\n");

  int paradas = paradasEnDoceItr(A, n);

  // for (int i = 0; i < n; i++) { 
    // fprintf(stdout, "A[%d]: %d\n", i, A[i]);
  // }

  fprintf(stdout, "Paradas: %d\n", paradas);
}

int paradasEnDoceItr(int* A, int n) {
  int paradas = 0;
  int acum = 0;

  for (int i = 0; i < n; i++) {
    if (acum + A[i] <= 24) {
      acum += A[i];
    } else {
      acum = A[i] - (24 - acum);
    }

    fprintf(stdout, "acum: %d\n", acum);
    if (acum == 12 || acum == 24) {
      paradas++;
    }
  }

  return paradas;
}
