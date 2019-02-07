#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct _Node {
	int numInts;
	int min;
	int max;
	unsigned int seed;
	FILE * input;
	FILE * output;
	FILE * count;
	int exitFlag;
};
typedef struct _Node Node;

Node parse(int, const char**);

#endif
