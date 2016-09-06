CFLAGS=-Wall
LIBS=-lcheck -lpthread -lm -lrt

all: calc

calc: main.o calculator.o
	gcc -o calc main.o calculator.o

main.o: main.c calculator.h
	gcc $(CFLAGS) -c main.c

calculator.o: calculator.c calculator.h
	gcc $(CFLAGS) -c calculator.c

test: calc-test
	./calc-test

calc-test: calculator-test.o calculator.o
	gcc -o calc-test calculator.o calculator-test.o $(LIBS)

calculator-test.o: calculator-test.c calculator.h
	gcc $(CFLAGS) -c calculator-test.c
