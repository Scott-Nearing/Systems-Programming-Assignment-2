#sn379745
#Scott Nearing
.SUFFIXES: .c .o
CC = gcc
CFLAGS = -g
.o.c:
	$(CC) $(CFLAGS) -c $<
p1: main.o funct.o
	gcc main.o funct.o -o p2
main.o: constants.h struct_def.h globals.h prototypes.h
stats.o: constants.h struct_def.h externs.h prototypes.h
clean:
	rm -f *.o core