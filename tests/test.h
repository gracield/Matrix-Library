#include <check.h>

#include "../s21_matrix.h"

#define OK 0
#define INCORRECT 1
#define CALCULATION_ERR 2

Suite *creat_tests();
Suite *remove_test();
Suite *equal_tests();
Suite *sum_tests();
Suite *sub_tests();
Suite *mult_number_tests();
Suite *mult_matrix_tests();
Suite *transpose_tests();
Suite *determinant_tests();
Suite *calc_complements_tests();
Suite *inverse_tests();
