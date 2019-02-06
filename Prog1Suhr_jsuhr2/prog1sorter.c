#include "prog1sorter.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int numInts, min, max = -1;
	char * inFile, outFile, countFile = NULL;
	int opt;
	while((opt = getopt(argc, argv, "u:n:m:M:i:o:c:")) != -1){
			switch(opt){
				case 'u':
					fprintf(stderr, "Learn How to Use This Command\n");
					return 0;
					break;
				case 'n':
					numInts = atoi(optarg);
					break;
				case 'm':
					min = atoi(optarg);
					break;
				case 'M':
					max = atoi(optarg);
					break;
				case 'i':
					inFile = optarg;
					break;
				case 'o':
					outFile = optarg;
					break;
				case 'c':
					countFile = optarg;
					break;
				case '?':
					fprintf(stderr, "Incorrect Command Line Arguments\n");
					return 0;
					break;
			}
	}
	if(numInts < 0){
		fprintf(stderr, "Number of integers cannot be less than 0\n");
		return 0;
	} else if(numInts == -1)
		numInts = 100;
	if(min == -1)
		min = 1;
	if(max > 1000000){
		fprintf(stderr, "Maximum integer value exceeds 1,000,000\n");
		return 0;
	} else if(max == -1)
		max = 255;
	if (max < min){
		fprintf(stderr, "Maximum integer value cannot be less than minimum integer value\n");
		return 0;
	}
	char * user = getenv("USER");
	printf("user: %s\n", user);
	return 0;
}
