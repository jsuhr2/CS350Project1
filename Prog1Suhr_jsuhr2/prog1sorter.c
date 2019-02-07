#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int countOccur(int *numbers, int numInts, int value){
	int count = 0;
	for(int i = 0; i < numInts; i++){
		if(*(numbers + i) == value)
			count++;
	}
	return count;
}

int compareFunction(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(int argc, char const *argv[]){
	int numInts = -1;
	int min = -1;
	int max = -1;
	FILE * input = NULL;
	FILE * output = NULL;
	FILE * count = NULL;
	clock_t start, end;
	double time_elapsed;
	
	Node inputs = parse(argc, argv);
	if(inputs.exitFlag == 1)
		return 0;

	numInts = inputs.numInts;
	min = inputs.min;
	max = inputs.max;
	input = inputs.input;
	output = inputs.output;
	count = inputs.count;


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

	int *numbers = (int *) malloc(numInts * sizeof(int));
	if(numbers == NULL){
		fprintf(stderr, "Malloc failed\n");
		return 0;
	}
	
	if(input != NULL){
		for(int i = 0; i < numInts; i++){
			fscanf(input, "%d", &numbers[i]);
			if(numbers[i] < min || numbers[i] > max){
				fprintf(stderr, "Integer in data is outside of the acceptable range\n");
				return 0;
			}
		}
	} else {
		for(int i = 0; i < numInts; i++){
			scanf("%d", &numbers[i]);
			if(feof(stdin))
				break;
			if(numbers[i] < min || numbers[i] > max){
				fprintf(stderr, "Integer in data is outside of the acceptable range\n");
				return 0;
			}
		}
	}
	
	qsort(numbers, numInts, sizeof(numbers[0]), compareFunction);

	if(output != NULL){
		for(int i = 0; i < numInts; i++){
			if(*(numbers + i) != 0)
				fprintf(output,"%d\n", *(numbers + i));
		}
	} else{
		for(int i = 0; i < numInts; i++){
			if(*(numbers + i) != 0)
				printf("%d\n", *(numbers + i));
		}
	}

	char * user = getenv("USER");
	char * t;
	if(count != NULL){
		for(t = user; *t != '\0'; t++){
			fprintf(count, "%c %d %d\n", *t, (int)*t, countOccur(numbers, numInts, (int)*t));
		}
	} else {
		for(t = user; *t != '\0'; t++){
			printf("%c %d %d\n", *t, (int)*t, countOccur(numbers, numInts, (int)*t));
		}
	}	

	end = clock();
	time_elapsed = ((double)(end - start))/CLOCKS_PER_SEC;
	fprintf(stderr, "Sorter Time Elapsed: %f\n", time_elapsed);
	
	free(numbers);
	if(input != NULL)
		fclose(input);
	if(output != NULL)
		fclose(output);
	if(count != NULL)
		fclose(count);
	return 0;
}
