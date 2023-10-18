C=gcc
CFLAGS= -Wall -Werror -Wextra -c -g -std=c11
GCOVFLAGS= -fprofile-arcs -ftest-coverage
LDFLAGS := -lcheck
ifeq ($(shell uname), Linux)
LDFLAGS += -lrt -lm 
endif
FUNCTIONS = functions/*.c 
TESTS = tests/*tests.c tests/test_starter.c
STYLE = $(FUNCTIONS) $(TESTS) *.h tests/*.h
all: clean s21_matrix.a

s21_matrix.a: clean
	$(CC) -c $(FUNCTIONS)
	ar -rc s21_matrix.a *.o 
	rm -rf *.o


test: s21_matrix.a
	$(CC) $(TESTS) s21_matrix.a $(LDFLAGS) -o test.out
	./test.out

gcov_report: 
	$(CC) -o result.out $(GCOVFLAGS) $(FUNCTIONS) $(TESTS) $(LDFLAGS)
	./result.out 
	lcov -capture --directory . --output-file main_coverage.info
	genhtml *.info -o ./gcov_report 
	rm -rf *.gcda *.gcno *.info result a.out 

clean:
	-rm -rf *.o
	-rm -rf *.a
	-rm -rf *.gcno
	-rm -rf *.gcda
	-rm -rf *.css
	-rm -rf *.html
	-rm -rf *.out
	-rm -rf gcov_report 

