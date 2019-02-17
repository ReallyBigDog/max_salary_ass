CC = gcc
CFLAGS = -Wall -std=c99

all: test test_performance

max_salary_naive.o: max_salary_naive.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_naive.c

max_salary_greedy.o: max_salary_greedy.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_greedy.c

test.o: test.c max_salary.h
	$(CC) $(CFLAGS) -c test.c

test_performance.o: test_performance.c max_salary.h
	$(CC) $(CFLAGS) -c test_performance.c

test: max_salary_naive.o max_salary_greedy.o test.o
	$(CC) $(CFLAGS) -o test max_salary_naive.o max_salary_greedy.o test.o

test_performance: max_salary_naive.o max_salary_greedy.o test_performance.o
	$(CC) $(CFLAGS) -o test_performance max_salary_naive.o max_salary_greedy.o test_performance.o

clean:
	rm *.o test test_performance
