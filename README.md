# Matrix-Library

Данная библиотека содержит основные функции для работы с матрицами: create_matrix (создание), remove_matrix (очистка и уничтожение), eq_matrix (сравнение), sum_matrix (сложение), sub_matrix (вычитание), mult_matrix (умножение), mult_number (умножение на число), transpose (транспонирование), determinant (вычисление определителя), calc_complements (вычисление матрицы алгебраических дополнений), inverse_matrix (поиск обратной матрицы).

В директории functions расположены все основные функции, s21_matrix.h является заголовочным файлом. 

В директории tests расположены unit-тесты

Основные цели в makefile: 
1. s21_matrix.a - производит сборку проекта
2. test - производит сборку проекта с последующим запуском автотестов 
3. gcov_report - производит сборку проекта с последующим запуском автотестов и генерацией html страницы с результатами покрытия тестами
5. clean - очистка проекта от исполняемых файлов
6. all - очистка и сборка проекта

