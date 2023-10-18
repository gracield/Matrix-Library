#include "test.h"

START_TEST(create_1) {
  matrix_t matrix;
  int err = 0;
  err = s21_create_matrix(5, 5, &matrix);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_2) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(5, 10, &matrix);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_3) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(10, 5, &matrix);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_4) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(create_5) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(create_6) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(-4, -4, &matrix);
  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(create_7) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(-4, 5, &matrix);
  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(create_8) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(4, -5, &matrix);
  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(create_9) {
  matrix_t matrix;
  int err = 0;

  err = s21_create_matrix(2, 2, NULL);
  ck_assert_int_eq(1, err);
}
END_TEST

Suite *creat_tests() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[104mCREAT_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, create_1);
  tcase_add_test(s21_matrix_tests, create_2);
  tcase_add_test(s21_matrix_tests, create_3);
  tcase_add_test(s21_matrix_tests, create_4);
  tcase_add_test(s21_matrix_tests, create_5);
  tcase_add_test(s21_matrix_tests, create_6);
  tcase_add_test(s21_matrix_tests, create_7);
  tcase_add_test(s21_matrix_tests, create_8);
  tcase_add_test(s21_matrix_tests, create_9);

  suite_add_tcase(s21_matrix, s21_matrix_tests);
  return s21_matrix;
}
