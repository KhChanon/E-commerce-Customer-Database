# This makefile is intended to build for term 2 project
# By Chanon Khanijoh 63070503408
# Note that this makefile assumes a Linux environment. The executables
# have no extension.
#

EXECUTABLES=project2

all : $(EXECUTABLES)

validation.o : validation.c fileio.h validation.h
	gcc -c validation.c

fileio.o : fileio.c fileio.h validation.h
	gcc -c fileio.c
	
mainmenu.o : mainmenu.c fileio.h validation.h
	gcc -c mainmenu.c

project2 : mainmenu.o fileio.o validation.o
	gcc -o project2 mainmenu.o fileio.o validation.o

clean : 
	-rm *.o
	-rm project2