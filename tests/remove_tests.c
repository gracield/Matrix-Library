#include "test.h"

START_TEST(remove_m) {
  matrix_t matrix_r;
  int err = 0;

  err = s21_create_matrix(3, 3, &matrix_r);
  s21_remove_matrix(&matrix_r);
  if (matrix_r.matrix != NULL) {
    err = INCORRECT;
  }
  ck_assert_int_eq(err, OK);
}
END_TEST

Suite *remove_test() {
  Suite *s21_matrix;
  TCase *s21_matrix_tests;
  s21_matrix = suite_create("\033[97m\033[100mREMOVE_TESTS\033[0m");
  s21_matrix_tests = tcase_create("tests");

  tcase_add_test(s21_matrix_tests, remove_m);

  suite_add_tcase(s21_matrix, s21_matrix_tests);

  return s21_matrix;
}
