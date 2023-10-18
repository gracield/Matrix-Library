#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1
#define calculation_error 2

#define SUCCESS 1  // for eq_matri
#define FAILURE 0  // for eq_matrix

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
void matrix_without_row_column(matrix_t *A, matrix_t *tmp, int del_row,
                               int del_column);
void s21_remove_matrix(matrix_t *A);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int check_matrix_exists(matrix_t *A);
int do_have_same_size(matrix_t *A, matrix_t *B);
double calc_determinant(matrix_t *A, int size);
