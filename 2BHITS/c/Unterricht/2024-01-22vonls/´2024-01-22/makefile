# Compiling the project into run.exe

run.exe: main.o object.o circle.o
	C:/mingw64/bin/gcc.exe -o run.exe main.o object.o circle.o

main.o: main.c object.h circle.h
	C:/mingw64/bin/gcc.exe -c main.c

object.o: object.c object.h
	C:/mingw64/bin/gcc.exe -c object.c

circle.o: circle.c circle.h
	C:/mingw64/bin/gcc.exe -c circle.c
