#include "test.h"

START_TEST(determinant_1) {
  matrix_t matrix_1;
  s21_create_matrix(3, 2, &matrix_1);
  double result;
  int err = 0;

  err = s21_determinant(NULL, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(CALCULATION_ERR, err);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t matrix_1;
  s21_create_matrix(3, 2, &matrix_1);
  double result;
  int err = 0;

  s21_create_matrix(3, 3, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][1] = -5;
  matrix_1.matrix[2][1] = 3.3;
  matrix_1.matrix[0][2] = -1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0.3;

  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  ck_assert_int_eq(1, result == -36);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t matrix_1;
  s21_create_matrix(3, 2, &matrix_1);
  double result;
  int err = 0;

  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[0][1] = 3;
  matrix_1.matrix[1][1] = 1;

  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  ck_assert_int_eq(1, result == -13);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t matrix_1;
  s21_create_matrix(3, 2, &matrix_1);
  double result;
  int err = 0;

  matrix_1.rows = -1;
  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *determinant_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[101mDETERMINANT_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, determinant_1);
  tcase_add_test(s21_matrix_tests, determinant_2);
  tcase_add_test(s21_matrix_tests, determinant_3);
  tcase_add_test(s21_matrix_tests, determinant_4);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
