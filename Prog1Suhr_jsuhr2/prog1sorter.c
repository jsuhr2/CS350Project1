#include "prog1sorter.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int countOccur(int *numbers, int value){
	int count = 0;
	int size = sizeof(numbers)/sizeof(numbers[0]);
	for(int i = 0; i < size; i++){
		if(*(numbers + 1) == value)
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
	char * inFile = NULL;
	char * outFile = NULL;
	char * countFile = NULL;
	clock_t start, end;
	double time_elapsed;
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

	char * user = getenv("USER");
	int *numbers = (int *) malloc(numInts * sizeof(int));
	if(numbers == NULL){
		fprintf(stderr, "Malloc failed\n");
		return 0;
	}
	
	int intsInFile = 0;
	if(inFile != NULL){
		FILE *input = fopen(inFile, "r");
		fscanf(input, "%d", &intsInFile);
		for(int i = 0; i < numInts; i++){
			fscanf(input, "%d", &numbers[i]);
		}
	} else {
		scanf("%d", &intsInFile);
		for(int i = 0; i < numInts; i++){
			scanf("%d", &numbers[i]);
		}
	}
	
	printf("\n");
	
	int sizeNumbers = sizeof(numbers)/sizeof(numbers[0]);
	qsort(numbers, sizeNumbers, sizeof(numbers[0]), compareFunction);

	if(outFile != NULL){
		FILE *output = fopen(outFile, "w");
		fprintf(output,"%d\n", numInts);
		for(int i = 0; i < numInts; i++){
			fprintf(output,"%d\n", *(numbers + i));
		}
	} else{
		printf("%d\n", numInts);
		for(int i = 0; i < numInts; i++){
			printf("%d\n", *(numbers + i));
		}
	}
	
	printf("\n");

	int sizeUser = sizeof(user)/sizeof(user[0]);
	if(countFile != NULL){
		FILE *count = fopen(outFile, "w");
		for(int i = 0; i < sizeUser; i++){
			fprintf(count, "%c %d %d\n", *(user + i), (int)*(user + i), 
				countOccur(numbers, (int)*(user + i)));
		}
	} else {
		for(int i = 0; i < sizeUser; i++){
			printf("%c %d %d\n", *(user + i), (int)*(user + i), 
				countOccur(numbers, (int)*(user + i)));
		}
	}	

	end = clock();
	time_elapsed = ((double)(end - start))/CLOCKS_PER_SEC;
	fprintf(stderr, "Time Elapsed: %d\n", time_elapsed);
	
	free(numbers);
/*
	fclose(input);
	fclose(output);
	fclose(count);
*/
	return 0;
}
