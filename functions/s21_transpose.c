#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int check_error = OK;

  if (check_matrix_exists(A) != SUCCESS) {
    check_error = ERROR;
  } else {
    if (s21_create_matrix(A->columns, A->rows, result) != OK) {
      check_error = ERROR;
    } else {
      for (int i = 0; check_error == OK && i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return check_error;
}
