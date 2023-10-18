#include "../s21_matrix.h"

int are_matrixs_equal(matrix_t *A, matrix_t *B) {
  int error_flag =
      SUCCESS;  // тут выгоднее считать, что все ок, чтобы выискать ошибку
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        error_flag =
            FAILURE;  // ошибка, если разница больше 7 знаков после запятой
      }
    }
  }
  return error_flag;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int check_flag = SUCCESS;

  if (check_matrix_exists(A) != SUCCESS || check_matrix_exists(B) != SUCCESS ||
      do_have_same_size(A, B) != SUCCESS) {
    check_flag = FAILURE;
  } else {
    check_flag = are_matrixs_equal(A, B);
  }

  return check_flag;
}
