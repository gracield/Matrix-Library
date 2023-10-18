#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int check_error = OK;
  if (check_matrix_exists(A) != SUCCESS || result == NULL) {
    check_error = ERROR;
  } else if (A->rows != A->columns) {
    check_error = calculation_error;
  } else {
    double det = 0;
    s21_determinant(A, &det);
    if (det != 0) {
      matrix_t tmp = {0};
      s21_calc_complements(A, result);
      s21_transpose(result, &tmp);
      s21_mult_number(&tmp, 1 / det, result);
      s21_remove_matrix(&tmp);
    } else {
      check_error = calculation_error;
    }
  }
  return check_error;
}
