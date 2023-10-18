#include "test.h"

START_TEST(sum_1) {
  matrix_t matrix_1, matrix_2, result, correct_res;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &correct_res);
  int err = 0;
  err = s21_sum_matrix(&matrix_1, &matrix_2, NULL);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_sum_matrix(&matrix_1, NULL, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_sum_matrix(NULL, &matrix_2, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_sum_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(OK, err);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(sum_2) {
  matrix_t matrix_1, matrix_2, result, correct_res;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 1.2;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  matrix_2.matrix[0][0] = 1;
  matrix_2.matrix[0][1] = 2;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 4;
  correct_res.matrix[0][0] = 2.2;
  correct_res.matrix[0][1] = 4;
  correct_res.matrix[1][0] = 6;
  correct_res.matrix[1][1] = 8;

  err = s21_sum_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(SUCCESS, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(sum_3) {
  matrix_t matrix_1, matrix_2, result, correct_res;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  matrix_2.matrix[0][0] = 1;
  matrix_2.matrix[0][1] = 2;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 4;
  correct_res.matrix[0][0] = 2;
  correct_res.matrix[0][1] = 4;
  correct_res.matrix[1][0] = 22;
  correct_res.matrix[1][1] = 8;

  err = s21_sum_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(sum_4) {
  matrix_t matrix_1, matrix_2, result;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  int err = 0;

  matrix_1.columns = -10;
  err = s21_sum_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(sum_5) {
  matrix_t matrix_1, matrix_2, result;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  int err = 0;

  s21_create_matrix(2, 6, &matrix_1);
  err = s21_sum_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(CALCULATION_ERR, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *sum_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[102mSUM_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, sum_1);
  tcase_add_test(s21_matrix_tests, sum_2);
  tcase_add_test(s21_matrix_tests, sum_3);
  tcase_add_test(s21_matrix_tests, sum_4);
  tcase_add_test(s21_matrix_tests, sum_5);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
