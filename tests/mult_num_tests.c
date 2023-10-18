#include "test.h"

START_TEST(mult_number_1) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &correct_res);
  int err = 0;

  err = s21_mult_number(NULL, 0, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_mult_number(&matrix_1, 0, NULL);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 1.1;
  matrix_1.matrix[0][1] = 2.0;
  matrix_1.matrix[1][0] = 3.0;
  matrix_1.matrix[1][1] = 4.0;
  correct_res.matrix[0][0] = 2.2;
  correct_res.matrix[0][1] = 4.0;
  correct_res.matrix[1][0] = 6.0;
  correct_res.matrix[1][1] = 8.0;

  err = s21_mult_number(&matrix_1, 2, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(SUCCESS, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &correct_res);
  int err = 0;

  correct_res.matrix[0][0] = 2.2;
  correct_res.matrix[0][1] = 4.0;
  correct_res.matrix[1][0] = 50.0;
  correct_res.matrix[1][1] = 8.0;

  err = s21_mult_number(&matrix_1, 2, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_number_4) {
  matrix_t matrix_1, result;
  s21_create_matrix(2, 2, &matrix_1);
  int err = 0;

  matrix_1.columns = -5;
  err = s21_mult_number(&matrix_1, 2, &result);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *mult_number_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[105mMUL_NUMBER_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, mult_number_1);
  tcase_add_test(s21_matrix_tests, mult_number_2);
  tcase_add_test(s21_matrix_tests, mult_number_3);
  tcase_add_test(s21_matrix_tests, mult_number_4);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
