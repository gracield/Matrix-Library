#include "../s21_matrix.h"

int check_matrix_exists(matrix_t *A) {
  int check_flag = SUCCESS;
  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    check_flag = FAILURE;
  return check_flag;
}

int do_have_same_size(matrix_t *A, matrix_t *B) {
  int check_flag = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    check_flag = FAILURE;
  }
  return check_flag;
}

void matrix_without_row_column(matrix_t *A, matrix_t *tmp, int row_to_avoid,
                               int column_to_avoid) {
  for (int A_row = 0, tmp_row = 0; A_row < A->rows; A_row++, tmp_row++) {
    if (A_row == row_to_avoid) A_row++;
    if (A_row == A->rows) break;
    for (int A_col = 0, tmp_col = 0; A_col < A->columns; A_col++, tmp_col++) {
      if (A_col == column_to_avoid) A_col++;
      if (A_col == A->columns) break;
      tmp->matrix[tmp_row][tmp_col] = A->matrix[A_row][A_col];
    }
  }
}

double calc_determinant(matrix_t *A, int size) {
  double result = 0;
  matrix_t tmp = {0};
  s21_create_matrix(size - 1, size - 1, &tmp);
  double tmp_res = 0;
  for (int i = 0, sign = 1; i < size; sign *= -1, i++) {
    matrix_without_row_column(A, &tmp, 0,
                              i);  // строю матрицу для нахождения минора
    s21_determinant(&tmp, &tmp_res);  // нахожу минор
    result += sign * A->matrix[0][i] * tmp_res;
  }
  s21_remove_matrix(&tmp);
  return result;
}
