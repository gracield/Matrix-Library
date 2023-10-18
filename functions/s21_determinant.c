#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int check_error = OK;

  if (check_matrix_exists(A) != SUCCESS) {
    check_error = ERROR;
  } else if (A->rows != A->columns) {
    check_error = calculation_error;
  } else {
    int size = A->rows;
    if (size == 1) {
      *result = A->matrix[0][0];
    } else if (size == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else {
      *result = calc_determinant(A, size);
    }
  }
  return check_error;
}
