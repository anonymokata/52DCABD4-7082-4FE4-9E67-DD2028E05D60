CFLAGS=-Wall
LIBS=-lcheck -lpthread -lm -lrt

all: calc

calc: main.o calculator.o decimal_roman.o roman_decimal.o errors.o
	gcc -o calc main.o calculator.o decimal_roman.o roman_decimal.o errors.o

main.o: main.c calculator.h decimal_roman.h roman_decimal.h errors.h
	gcc $(CFLAGS) -c main.c

calculator.o: calculator.c calculator.h decimal_roman.c decimal_roman.h roman_decimal.c roman_decimal.h errors.c errors.h
	gcc $(CFLAGS) -c calculator.c decimal_roman.c roman_decimal.c errors.c

test: calc-test
	./calc-test

calc-test: calculator-test.o calculator.o
	gcc -o calc-test calculator.o decimal_roman.o roman_decimal.o errors.o calculator-test.o $(LIBS)

calculator-test.o: calculator-test.c calculator.h decimal_roman.h roman_decimal.h errors.h
	gcc $(CFLAGS) -c calculator-test.c
