#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int check_error = OK;
  if (check_matrix_exists(A) != SUCCESS || check_matrix_exists(B) != SUCCESS) {
    check_error = ERROR;
  } else {
    if (A->rows != B->rows || A->columns != B->columns) {
      check_error = calculation_error;
    } else if (s21_create_matrix(A->rows, B->columns, result) != OK) {
      check_error = ERROR;
    } else {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return check_error;
}
