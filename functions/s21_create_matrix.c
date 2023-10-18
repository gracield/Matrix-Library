#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag_error = ERROR;

  if (rows > 0 && columns > 0 &&
      result != NULL) {  // проверка на возможность созда тьматрицк
    flag_error = OK;
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)calloc(rows, sizeof(double *));

    if (result->matrix) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }
    } else {
      flag_error = ERROR;
    }
  }

  return flag_error;
}
