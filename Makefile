# @author: Telmen Enkhtuvshin
# Makefile helper to manage compilation of Lab2.c file

# Specifying compiler
CC = gcc

# lab2 executable file is dependent on object file
lab2: Lab2.o
	$(CC) Lab2.o -o lab2

# Object file is dependent on source file 
Lab2.o: Lab2.c
	$(CC) -c Lab2.c -o Lab2.o

# Cleaning object files
clean:
	rm -f *.o final