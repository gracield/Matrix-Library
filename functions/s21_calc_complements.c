#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int check_error = OK;
  if (check_matrix_exists(A) != SUCCESS || result == NULL) {
    check_error = ERROR;
  } else if (A->rows != A->columns) {
    check_error = calculation_error;
  } else {
    matrix_t tmp = {0};
    if (s21_create_matrix(A->rows, A->columns, result) != OK ||
        s21_create_matrix(A->rows - 1, A->rows - 1, &tmp) != OK) {
      check_error = ERROR;
    } else {
      double sign = -1;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_without_row_column(A, &tmp, i, j);
          s21_determinant(&tmp, &result->matrix[i][j]);
          result->matrix[i][j] *= pow(sign, i + j);
        }
      }
    }
    s21_remove_matrix(&tmp);
  }
  return check_error;
}
