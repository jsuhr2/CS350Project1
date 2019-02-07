#include "parser.h"

Node parse(int argc, const char **argv){
	Node inputs;
	if(strcmp(argv[0], "./prog1sorter") == 0){
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
						for(int i = 0; optarg[i] != '\0'; i++){
							if(isdigit(optarg[i]) == 0){
								fprintf(stderr, "Incorrect argument for number of integers\n");
								inputs.exitFlag = 1;
								break;
							}
						}
						inputs.numInts = atoi(optarg);
						break;
					case 'm':
						for(int i = 0; optarg[i] != '\0'; i++){
							if(isdigit(optarg[i]) == 0){
								fprintf(stderr, "Incorrect argument for minimum integer\n");
								inputs.exitFlag = 1;
								break;
							}
						}
						inputs.min = atoi(optarg);
						break;
					case 'M':
						for(int i = 0; optarg[i] != '\0'; i++){
							if(isdigit(optarg[i]) == 0){
								fprintf(stderr, "Incorrect argument for maximum integer\n");
								inputs.exitFlag = 1;
								break;
							}
						}
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
	} else if(strcmp(argv[0], "./prog1generator") == 0){
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
						for(int i = 0; optarg[i] != '\0'; i++){
							if(isdigit(optarg[i]) == 0){
								fprintf(stderr, "Incorrect argument for number of integers\n");
								inputs.exitFlag = 1;
								break;
							}
						}
						inputs.numInts = atoi(optarg);
						break;
					case 'm':
						for(int i = 0; optarg[i] != '\0'; i++){
							if(isdigit(optarg[i]) == 0){
								fprintf(stderr, "Incorrect argument for minimum integer\n");
								inputs.exitFlag = 1;
								break;
							}
						}
						inputs.min = atoi(optarg);
						break;
					case 'M':
						for(int i = 0; optarg[i] != '\0'; i++){
							if(isdigit(optarg[i]) == 0){
								fprintf(stderr, "Incorrect argument for maximum integer\n");
								inputs.exitFlag = 1;
								break;
							}
						}
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
	}
	return inputs;
}
