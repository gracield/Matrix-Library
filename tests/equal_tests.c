#include "test.h"

START_TEST(equal_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  int err = 0;
  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(SUCCESS, err);
  err = s21_eq_matrix(&matrix_1, NULL);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int err = 0;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);

  matrix_1.matrix[0][0] = 5.0;
  matrix_1.matrix[0][1] = 4.0;
  matrix_1.matrix[0][2] = 3.0;
  matrix_1.matrix[0][3] = 2.0;
  matrix_1.matrix[0][4] = 1.0;
  matrix_1.matrix[1][0] = 1.0;
  matrix_1.matrix[1][1] = 2.0;
  matrix_1.matrix[1][2] = 3.0;
  matrix_1.matrix[1][3] = 4.0;
  matrix_1.matrix[1][4] = 5.0;
  matrix_1.matrix[2][0] = 2.0;
  matrix_1.matrix[2][1] = 1.0;
  matrix_1.matrix[2][2] = 3.0;
  matrix_1.matrix[2][3] = 3.0;
  matrix_1.matrix[2][4] = 5.0;
  matrix_1.matrix[3][0] = 3.0;
  matrix_1.matrix[3][1] = 2.0;
  matrix_1.matrix[3][2] = 4.0;
  matrix_1.matrix[3][3] = 1.0;
  matrix_1.matrix[3][4] = 5.0;
  matrix_1.matrix[4][0] = 5.0;
  matrix_1.matrix[4][1] = 3.0;
  matrix_1.matrix[4][2] = 1.0;
  matrix_1.matrix[4][3] = 2.0;
  matrix_1.matrix[4][4] = 4.0;

  matrix_2.matrix[0][0] = 5.0;
  matrix_2.matrix[0][1] = 4.0;
  matrix_2.matrix[0][2] = 3.0;
  matrix_2.matrix[0][3] = 2.0;
  matrix_2.matrix[0][4] = 1.0;
  matrix_2.matrix[1][0] = 1.0;
  matrix_2.matrix[1][1] = 2.0;
  matrix_2.matrix[1][2] = 3.0;
  matrix_2.matrix[1][3] = 4.0;
  matrix_2.matrix[1][4] = 5.0;
  matrix_2.matrix[2][0] = 2.0;
  matrix_2.matrix[2][1] = 1.0;
  matrix_2.matrix[2][2] = 3.0;
  matrix_2.matrix[2][3] = 3.0;
  matrix_2.matrix[2][4] = 5.0;
  matrix_2.matrix[3][0] = 3.0;
  matrix_2.matrix[3][1] = 2.0;
  matrix_2.matrix[3][2] = 4.0;
  matrix_2.matrix[3][3] = 1.0;
  matrix_2.matrix[3][4] = 5.0;
  matrix_2.matrix[4][0] = 5.0;
  matrix_2.matrix[4][1] = 3.0;
  matrix_2.matrix[4][2] = 1.0;
  matrix_2.matrix[4][3] = 2.0;
  matrix_2.matrix[4][4] = 4.0;

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(SUCCESS, err);
  matrix_1.matrix[1][1] = 8.0;
  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int err = 0;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);

  matrix_1.matrix[0][0] = 5.0;
  matrix_1.matrix[0][1] = 4.0;
  matrix_1.matrix[0][2] = 3.0;
  matrix_1.matrix[0][3] = 2.0;
  matrix_1.matrix[0][4] = 1.0;
  matrix_1.matrix[1][0] = 1.0;
  matrix_1.matrix[1][1] = 2.0;
  matrix_1.matrix[1][2] = 3.0;
  matrix_1.matrix[1][3] = 4.0;
  matrix_1.matrix[1][4] = 5.0;
  matrix_1.matrix[2][0] = 2.0;
  matrix_1.matrix[2][1] = 1.0;
  matrix_1.matrix[2][2] = 3.0;
  matrix_1.matrix[2][3] = 3.0;
  matrix_1.matrix[2][4] = 5.0;
  matrix_1.matrix[3][0] = 3.0;
  matrix_1.matrix[3][1] = 2.0;
  matrix_1.matrix[3][2] = 4.0;
  matrix_1.matrix[3][3] = 1.0;
  matrix_1.matrix[3][4] = 5.0;
  matrix_1.matrix[4][0] = 5.0;
  matrix_1.matrix[4][1] = 3.0;
  matrix_1.matrix[4][2] = 1.0;
  matrix_1.matrix[4][3] = 2.0;
  matrix_1.matrix[4][4] = 4.0;

  matrix_2.matrix[0][0] = 5.0;
  matrix_2.matrix[0][1] = 4.0;
  matrix_2.matrix[0][2] = 3.0;
  matrix_2.matrix[0][3] = 2.0;
  matrix_2.matrix[0][4] = 1.0;
  matrix_2.matrix[1][0] = 1.0;
  matrix_2.matrix[1][1] = 2.0;
  matrix_2.matrix[1][2] = 3.0;
  matrix_2.matrix[1][3] = 4.0;
  matrix_2.matrix[1][4] = 5.0;
  matrix_2.matrix[2][0] = 2.0;
  matrix_2.matrix[2][1] = 1.0;
  matrix_2.matrix[2][2] = 3.0;
  matrix_2.matrix[2][3] = 3.0;
  matrix_2.matrix[2][4] = 5.0;
  matrix_2.matrix[3][0] = 3.0;
  matrix_2.matrix[3][1] = 2.0;
  matrix_2.matrix[3][2] = 4.0;
  matrix_2.matrix[3][3] = 1.0;
  matrix_2.matrix[3][4] = 5.0;
  matrix_2.matrix[4][0] = 5.0;
  matrix_2.matrix[4][1] = 3.0;
  matrix_2.matrix[4][2] = 1.0;
  matrix_2.matrix[4][3] = 2.0;
  matrix_2.matrix[4][4] = 4.0;

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(SUCCESS, err);
  matrix_1.matrix[1][1] = 8.0;
  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_4) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int err = 0;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);

  matrix_1.matrix[0][0] = 5;
  matrix_1.matrix[0][1] = 4;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[0][3] = 2;
  matrix_1.matrix[0][4] = 1;
  matrix_1.matrix[1][0] = 1;
  matrix_1.matrix[1][1] = 2;
  matrix_1.matrix[1][2] = 3;
  matrix_1.matrix[1][3] = 4;
  matrix_1.matrix[1][4] = 5;
  matrix_1.matrix[2][0] = 2;
  matrix_1.matrix[2][1] = 1;
  matrix_1.matrix[2][2] = 3;
  matrix_1.matrix[2][3] = 3;
  matrix_1.matrix[2][4] = 5;
  matrix_1.matrix[3][0] = 3;
  matrix_1.matrix[3][1] = 2;
  matrix_1.matrix[3][2] = 4;
  matrix_1.matrix[3][3] = 1;
  matrix_1.matrix[3][4] = 5;
  matrix_1.matrix[4][0] = 5;
  matrix_1.matrix[4][1] = 3;
  matrix_1.matrix[4][2] = 1;
  matrix_1.matrix[4][3] = 2;
  matrix_1.matrix[4][4] = 4;

  matrix_2.matrix[0][0] = 5;
  matrix_2.matrix[0][1] = 4;
  matrix_2.matrix[0][2] = 3;
  matrix_2.matrix[0][3] = 2;
  matrix_2.matrix[0][4] = 1;
  matrix_2.matrix[1][0] = 1;
  matrix_2.matrix[1][1] = 2;
  matrix_2.matrix[1][2] = 3;
  matrix_2.matrix[1][3] = 4;
  matrix_2.matrix[1][4] = 5;
  matrix_2.matrix[2][0] = 2;
  matrix_2.matrix[2][1] = 1;
  matrix_2.matrix[2][2] = 3;
  matrix_2.matrix[2][3] = 3;
  matrix_2.matrix[2][4] = 5;
  matrix_2.matrix[3][0] = 3;
  matrix_2.matrix[3][1] = 2;
  matrix_2.matrix[3][2] = 4;
  matrix_2.matrix[3][3] = 1;
  matrix_2.matrix[3][4] = 5;
  matrix_2.matrix[4][0] = 5;
  matrix_2.matrix[4][1] = 3;
  matrix_2.matrix[4][2] = 1;
  matrix_2.matrix[4][3] = 2;
  matrix_2.matrix[4][4] = 4;

  matrix_2.matrix[1][1] = 5;
  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(FAILURE, err);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(5, 5, &matrix_2);
  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int err = 0;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);

  matrix_1.columns = 0;
  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(FAILURE, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_7) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int err = 0;

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(SUCCESS, err);

  err = s21_eq_matrix(&matrix_1, NULL);
  ck_assert_int_eq(FAILURE, err);

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(SUCCESS, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *equal_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[101mEQUAL_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, equal_1);
  tcase_add_test(s21_matrix_tests, equal_2);
  tcase_add_test(s21_matrix_tests, equal_3);
  tcase_add_test(s21_matrix_tests, equal_4);
  tcase_add_test(s21_matrix_tests, equal_6);
  tcase_add_test(s21_matrix_tests, equal_7);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
