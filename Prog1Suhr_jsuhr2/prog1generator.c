#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	int numInts = -1;
	int min = -1; 
	int max = -1;
	FILE * output = NULL;
	unsigned int seed = -1;
	int generated;
	clock_t start, end;
	double time_elapsed;
	

	Node inputs = parseGenerator(argc, argv);

	if(inputs.exitFlag == 1)
		return 0;

	numInts = inputs.numInts;
	min = inputs.min;
	max = inputs.max;
	output = inputs.output;
	seed = inputs.seed;

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
	
	if(output != NULL){
		for(int i = 0; i < numInts; i++){
			do{
				generated = rand();
			} while((generated < min) || (generated > max));
			fprintf(output,"%d\n", generated);
		}
	} else{
		for(int i = 0; i < numInts; i++){
			do{
				generated = rand();
			} while((generated < min) || (generated > max));
			printf("%d\n", generated);
		}
	}

	end = clock();
	time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
	fprintf(stderr, "Time Elapsed: %f\n", time_elapsed);
	if(output != NULL)
		fclose(output);
	return 0;
}
