# Compiling the project into run.exe
CC = gcc

run.exe: main.o figur.o kreis.o rechteck.o	
	gcc -o run.exe main.o figur.o kreis.o rechteck.o

main.o: main.c figur.h kreis.h rechteck.h
	CC -c main.c

figur.o: figur.c figur.h
	CC -c object.c

kreis.o: kreis.c kreis.h
	CC -c kreis.c

rechteck.o: rechteck.c rechteck.h
	CC -c rechteck.c
