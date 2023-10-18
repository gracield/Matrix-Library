#include "test.h"

START_TEST(transpose_1) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(2, 3, &correct_res);
  int err = 0;

  err = s21_transpose(NULL, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_transpose(&matrix_1, NULL);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(2, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 4;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[2][1] = 6;
  correct_res.matrix[0][0] = 1;
  correct_res.matrix[0][1] = 2;
  correct_res.matrix[0][2] = 3;
  correct_res.matrix[1][0] = 4;
  correct_res.matrix[1][1] = 5;
  correct_res.matrix[1][2] = 6;

  err = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(SUCCESS, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(2, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 4;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[2][1] = 6;
  correct_res.matrix[0][0] = 1;
  correct_res.matrix[0][1] = 2;
  correct_res.matrix[0][2] = 3;
  correct_res.matrix[1][0] = 4;
  correct_res.matrix[1][1] = 5;
  correct_res.matrix[1][2] = 6;

  correct_res.matrix[1][2] = 10;
  err = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(2, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 4;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[2][1] = 6;
  correct_res.matrix[0][0] = 1;
  correct_res.matrix[0][1] = 2;
  correct_res.matrix[0][2] = 3;
  correct_res.matrix[1][0] = 4;
  correct_res.matrix[1][1] = 5;
  correct_res.matrix[1][2] = 6;

  matrix_1.columns = 0;
  err = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

Suite *transpose_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[100mTRANSPOSE_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, transpose_1);
  tcase_add_test(s21_matrix_tests, transpose_2);
  tcase_add_test(s21_matrix_tests, transpose_3);
  tcase_add_test(s21_matrix_tests, transpose_4);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
