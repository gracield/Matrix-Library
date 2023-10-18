#include "test.h"

START_TEST(calc_complements_1) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  err = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_calc_complements(&matrix_1, NULL);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(CALCULATION_ERR, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
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
  correct_res.matrix[0][0] = -1.5;
  correct_res.matrix[0][1] = -1.5;
  correct_res.matrix[0][2] = 31.5;
  correct_res.matrix[1][0] = -3.6;
  correct_res.matrix[1][1] = 3.6;
  correct_res.matrix[1][2] = -3.6;
  correct_res.matrix[2][0] = -5;
  correct_res.matrix[2][1] = -5;
  correct_res.matrix[2][2] = -15;

  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(SUCCESS, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][1] = -5;
  matrix_1.matrix[2][1] = 3.3;
  matrix_1.matrix[0][2] = -1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0.3;
  correct_res.matrix[0][0] = -1.5;
  correct_res.matrix[0][1] = -1.5;
  correct_res.matrix[0][2] = 31.5;
  correct_res.matrix[1][0] = -3.6;
  correct_res.matrix[1][1] = 3.6;
  correct_res.matrix[1][2] = -3.6;
  correct_res.matrix[2][0] = -5;
  correct_res.matrix[2][1] = -5;
  correct_res.matrix[2][2] = -15;

  correct_res.matrix[1][2] = 100;

  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  matrix_1.rows = -3;
  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

Suite *calc_complements_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[102mCALC_COMPLEMENTS_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, calc_complements_1);
  tcase_add_test(s21_matrix_tests, calc_complements_2);
  tcase_add_test(s21_matrix_tests, calc_complements_3);
  tcase_add_test(s21_matrix_tests, calc_complements_4);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
