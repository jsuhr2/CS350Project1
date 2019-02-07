#include "parser.h"

Node parseSorter(int argc, const char **argv){
	Node inputs;
	inputs.numInts = -1;
	inputs.max = -1;
	inputs.min = -1;
	inputs.input = NULL;
	inputs.output = NULL;
	inputs.count = NULL;
	inputs.exitFlag = 0;
	int opt;
	while((opt = getopt(argc, argv, "un:m:M:i:o:c:")) != -1){
			switch(opt){
				case 'u':
					fprintf(stderr, "prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]\n");
					inputs.exitFlag = 1;
					return inputs;
					break;
				case 'n':
					inputs.numInts = atoi(optarg);
					break;
				case 'm':
					inputs.min = atoi(optarg);
					break;
				case 'M':
					inputs.max = atoi(optarg);
					break;
				case 'i':
					inputs.input = fopen(optarg, "r");
					break;
				case 'o':
					inputs.output = fopen(optarg, "w");
					break;
				case 'c':
					inputs.count = fopen(optarg, "w");
					break;
				case '?':
					fprintf(stderr, "prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]\n");
					inputs.exitFlag = 1;
					return inputs;
					break;
			}
	}
	return inputs;
}

Node parseGenerator(int argc, const char **argv){
	Node inputs;
	inputs.numInts = -1;
	inputs.max = -1;
	inputs.min = -1;
	inputs.seed = -1;
	inputs.output = NULL;
	inputs.exitFlag = 0;
	int opt;
	while((opt = getopt(argc, argv, "un:m:M:s:o:")) != -1){
			switch(opt){
				case 'u':
					fprintf(stderr, "prog1generator [-u] [-n <num-integers>] [-m <min-int>]	[-M <max-int>] [-s <seed>] [-o <output-file-name>]\n");
					inputs.exitFlag = 1;
					return inputs;
					break;
				case 'n':
					inputs.numInts = atoi(optarg);
					break;
				case 'm':
					inputs.min = atoi(optarg);
					break;
				case 'M':
					inputs.max = atoi(optarg);
					break;
				case 's':
					inputs.seed = atoi(optarg);
					break;
				case 'o':
					inputs.output = fopen(optarg, "w");
					break;
				case '?':
					fprintf(stderr, "prog1generator [-u] [-n <num-integers>] [-m <min-int>]	[-M <max-int>] [-s <seed>] [-o <output-file-name>]\n");
					inputs.exitFlag = 1;
					return inputs;
					break;
			}
	}
	return inputs;
}
