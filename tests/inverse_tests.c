#include "test.h"

START_TEST(inverse_matrix_1) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  err = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_inverse_matrix(&matrix_1, NULL);
  ck_assert_int_eq(INCORRECT, err);
  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(CALCULATION_ERR, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t matrix_1, result, correct_res;
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
  correct_res.matrix[0][0] = -1.5 / -36;
  correct_res.matrix[1][0] = -1.5 / -36;
  correct_res.matrix[2][0] = 31.5 / -36;
  correct_res.matrix[0][1] = -3.6 / -36;
  correct_res.matrix[1][1] = 3.6 / -36;
  correct_res.matrix[2][1] = -3.6 / -36;
  correct_res.matrix[0][2] = -5. / -36;
  correct_res.matrix[1][2] = -5. / -36;
  correct_res.matrix[2][2] = -15. / -36;

  correct_res.matrix[2][2] = -14. / -36;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(OK, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(inverse_matrix_3) {
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
  correct_res.matrix[0][0] = -1.5 / -36;
  correct_res.matrix[1][0] = -1.5 / -36;
  correct_res.matrix[2][0] = 31.5 / -36;
  correct_res.matrix[0][1] = -3.6 / -36;
  correct_res.matrix[1][1] = 3.6 / -36;
  correct_res.matrix[2][1] = -3.6 / -36;
  correct_res.matrix[0][2] = -5. / -36;
  correct_res.matrix[1][2] = -5. / -36;
  correct_res.matrix[2][2] = -15. / -36;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(inverse_matrix_4) {
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
  correct_res.matrix[0][0] = -1.5 / -36;
  correct_res.matrix[1][0] = -1.5 / -36;
  correct_res.matrix[2][0] = 31.5 / -36;
  correct_res.matrix[0][1] = -3.6 / -36;
  correct_res.matrix[1][1] = 3.6 / -36;
  correct_res.matrix[2][1] = -3.6 / -36;
  correct_res.matrix[0][2] = -5. / -36;
  correct_res.matrix[1][2] = -5. / -36;
  correct_res.matrix[2][2] = -15. / -36;

  correct_res.matrix[2][2] = -14. / -36;

  matrix_1.matrix[0][2] = 0;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(CALCULATION_ERR, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  matrix_1.rows = -2;
  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(INCORRECT, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
}
END_TEST

Suite *inverse_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[103mINVERSE_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, inverse_matrix_1);
  tcase_add_test(s21_matrix_tests, inverse_matrix_2);
  tcase_add_test(s21_matrix_tests, inverse_matrix_3);
  tcase_add_test(s21_matrix_tests, inverse_matrix_4);
  tcase_add_test(s21_matrix_tests, inverse_matrix_5);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
