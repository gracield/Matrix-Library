#include "test.h"

void s21_Srunner(Suite** suite);

int main(void) {
  printf("\n\n \033[97m\033[105m|| S21_MATRIX ||\033[0m \n\n");
  Suite* suite_void[] = {creat_tests(),       remove_test(),
                         equal_tests(),       sum_tests(),
                         sub_tests(),         mult_number_tests(),
                         mult_matrix_tests(), transpose_tests(),
                         determinant_tests(), calc_complements_tests(),
                         inverse_tests(),     NULL};

  s21_Srunner(suite_void);

  return 0;
}

void s21_Srunner(Suite** suite) {
  for (int i = 0; suite[i]; ++i) {
    SRunner* suite_runner = srunner_create(suite[i]);
    srunner_run_all(suite_runner, CK_NORMAL);
    srunner_free(suite_runner);
  }
}
