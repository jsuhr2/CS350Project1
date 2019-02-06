#include "prog1generator.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	int numInts = -1;
	int min = -1; 
	int max = -1;
	char * outFile = NULL;
	long seed = -1;
	int opt;
	int generated;
	clock_t start, end;
	double time_elapsed;
	while((opt = getopt(argc, argv, "un:m:M:s:o:")) != -1){
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
				case 's':
					seed = optarg;
					break;
				case 'o':
					outFile = optarg;
					break;
				case '?':
					fprintf(stderr, "Incorrect Command Line Arguments\n");
					return 0;
					break;
			}
	}
	start = clock();
	if(numInts == -1)
		numInts = 100;
	else if(numInts < 0){
		fprintf(stderr, "Number of integers cannot be less than 0\n");
		return 0;
	}
	if(min == -1)
		min = 1;
	else if(min < 1){
		fprintf(stderr, "Minimum integer value cannot be less than 1\n");
		return 0;
	}
	if(max == -1)
		max = 255;
	else if(max > 1000000){
		fprintf(stderr, "Maximum integer value cannot exceed 1,000,000\n");
		return 0;
	}
	if (max < min){
		fprintf(stderr, "Maximum integer value cannot be less than minimum integer value\n");
		return 0;
	}
	if(seed != -1)
		srand(seed);
	else
		srand(time(0));
	if(outFile != NULL){
		FILE *output = fopen(outFile, "w");
		fprintf(output,"%d\n", numInts);
		for(int i = 0; i < numInts; i++){
			do{
				generated = rand();
			} while((generated < min) || (generated > max));
			fprintf(output,"%d\n", generated);
		}
	} else{
		printf("%d\n", numInts);
		for(int i = 0; i < numInts; i++){
			do{
				generated = rand();
			} while((generated < min) || (generated > max));
			printf("%d\n", generated);
		}
	}
	end = clock();
	time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
	fprintf(stderr, "Time Elapsed: %d\n", time_elapsed);
//	fclose(output);
	return 0;
}
