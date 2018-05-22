//Nash Baughn
//cruzId: nbaughn
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadGraph.h"
#include "dfsTrace1.h"

void findSCCs(IntVec* adjVertices, int n){
	//arrays for discover time, finish time, finishStak
	int* discover_times = (int*)calloc(n, sizeof(int));
	int* finish_times = (int*)calloc(n, sizeof(int));
	int* finishStak =  (int*)calloc(n, sizeof(int));
	//adjVerticesT = //transpose adjVertices

	int* discover_times2 = (int*)calloc(n, sizeof(int));
	int* finish_times2 = (int*)calloc(n, sizeof(int));
	int* finishStak2 =  (int*)calloc(n, sizeof(int));
	printf("%d\n", n);
	int dfs = dfsSweep(adjVertices, n);
}

void dashV(FILE *file, int n){
	//not really needed to return adjVertices seeing that its passed right back to a function in loadGraph.c  

	IntVec* adjVertices = (IntVec*)loadIntVecGraph(file);
	//printIntVecNodes(adjVertices);

	findSCCs(adjVertices, n);

}

void dashL(FILE *file, int n){
	//not really needed to return adjVertices seeing that its passed right back to a function in loadGraph.c
	IntList* adjVertices = (IntList*)loadIntListGraph(file);
	printIntListNodes(adjVertices);
}


int main( int argc, char *argv[])  {
	printf("fuck\n");
	printf("fuck\n");
	FILE *file = NULL;

	if (argc == 1){
	  	printf("No files inputed\n");
	  	exit(1);
	}else{	
		file = fopen(argv[2], "r");
		if (file == NULL){
			printf("Error: Could not find file %s\n", argv[2]);
			exit(1);
		}
	}
	FILE *nfile = fopen(argv[2], "r");

	char line[2048];
	//Get the first line to get n (number of nodes) or check for an error
	char *nline = fgets(line, sizeof(line), nfile);
	int n, q, sscanfRetn;
	sscanfRetn = sscanf(nline, " %d %d ", &n, &q);
	if(sscanfRetn != 1){
		//Error if first line has more than one value
		printf("Error line at 1: Only one value\n");
		exit(1);
	}

	//check if there are more than 3 arguments
	if(argc != 3){
		printf("error: there should only be a file and one flag (-V or -L)\n");
	}
	//check for -V flag
	else if(strcmp(argv[1], "-V") == 0){
		dashV(file, n);
	//check for -L flag
	}else if(strcmp(argv[1], "-L") == 0){
		dashL(file, n);
	}else{
		printf("error\n");
	}
	exit(0);
}

