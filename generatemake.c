#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	FILE* fd = fopen("Makefile", "a");
	
	fprintf(fd, "CC = g++\n");
	fprintf(fd, "CFLAGS = -std=c++11 -o\n");
	
	fprintf(fd, "all: ");
	for (int i=1; i<617; i++) {
		fprintf(fd, "p%d ", i);
	} fprintf(fd, "\n");
	
	for (int i=1; i<617; i++) {
	    fprintf(fd, "p%d: p%d.cpp\n", i,i);
	    fprintf(fd, "\t@$(CC) $(CFLAGS) p%d p%d.cpp\n", i,i);
	}

	fprintf(fd, "clean:\n\t@rm -f ");
	for (int i=1; i<617; i++) {
		fprintf(fd, "p%d ", i);
	} fprintf(fd, "\n");

	fclose(fd);
	return 0;
}