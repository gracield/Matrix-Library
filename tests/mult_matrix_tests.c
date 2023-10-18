#include "test.h"

START_TEST(mult_matrix_1) {
  matrix_t matrix_1, matrix_2, result, correct_res;
  s21_create_matrix(3, 1, &matrix_1);
  s21_create_matrix(1, 3, &matrix_2);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  err = s21_mult_matrix(NULL, &matrix_2, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_mult_matrix(&matrix_1, NULL, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_mult_matrix(&matrix_1, &matrix_2, NULL);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t matrix_1, matrix_2, result, correct_res;
  s21_create_matrix(3, 1, &matrix_1);
  s21_create_matrix(1, 3, &matrix_2);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_2.matrix[0][0] = 2;
  matrix_2.matrix[0][1] = 5;
  matrix_2.matrix[0][2] = 3;
  correct_res.matrix[0][0] = 4.0;
  correct_res.matrix[0][1] = 10.0;
  correct_res.matrix[0][2] = 6.0;
  correct_res.matrix[1][0] = 10;
  correct_res.matrix[1][1] = 25;
  correct_res.matrix[1][2] = 15;
  correct_res.matrix[2][0] = 6;
  correct_res.matrix[2][1] = 15;
  correct_res.matrix[2][2] = 9;

  err = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(SUCCESS, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t matrix_1, matrix_2, result, correct_res;
  s21_create_matrix(3, 1, &matrix_1);
  s21_create_matrix(1, 3, &matrix_2);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_2.matrix[0][0] = 2;
  matrix_2.matrix[0][1] = 5;
  matrix_2.matrix[0][2] = 3;
  correct_res.matrix[0][0] = 4.0;
  correct_res.matrix[0][1] = 10.0;
  correct_res.matrix[0][2] = 6.0;
  correct_res.matrix[1][0] = 10;
  correct_res.matrix[1][1] = 25;
  correct_res.matrix[1][2] = 15;
  correct_res.matrix[2][0] = 6;
  correct_res.matrix[2][1] = 15;
  correct_res.matrix[2][2] = 9;

  correct_res.matrix[2][2] = 100;

  err = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t matrix_1, matrix_2, result, correct_res;
  s21_create_matrix(3, 1, &matrix_1);
  s21_create_matrix(1, 3, &matrix_2);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_2.matrix[0][0] = 2;
  matrix_2.matrix[0][1] = 5;
  matrix_2.matrix[0][2] = 3;
  correct_res.matrix[0][0] = 4.0;
  correct_res.matrix[0][1] = 10.0;
  correct_res.matrix[0][2] = 6.0;
  correct_res.matrix[1][0] = 10;
  correct_res.matrix[1][1] = 25;
  correct_res.matrix[1][2] = 15;
  correct_res.matrix[2][0] = 6;
  correct_res.matrix[2][1] = 15;
  correct_res.matrix[2][2] = 9;

  matrix_2.rows = -1;
  err = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(INCORRECT, err);

  matrix_2.rows = 5;
  err = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(CALCULATION_ERR, err);

  s21_create_matrix(4, 4, &matrix_2);
  err = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(CALCULATION_ERR, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&correct_res);
}
END_TEST

Suite *mult_matrix_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[106mMUL_MATRIX_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, mult_matrix_1);
  tcase_add_test(s21_matrix_tests, mult_matrix_2);
  tcase_add_test(s21_matrix_tests, mult_matrix_3);
  tcase_add_test(s21_matrix_tests, mult_matrix_4);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
