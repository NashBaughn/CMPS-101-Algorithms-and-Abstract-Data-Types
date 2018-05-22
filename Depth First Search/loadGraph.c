//nash baughn
//cruzId: nbaughn
#include "loadGraph.h"
#include "intVec.h"
#include "intList.h"
#include <stdio.h>
#include <stdlib.h>
//math.h is for fucntion at line 80.
#include <math.h>

static int n=0, m=0;


void* loadIntListGraph(FILE *file){
	char line[2048];
	//Get the first line to get n (number of nodes) or check for an error
	char *nline = fgets(line, sizeof(line), file);
	int p, q, wgt, sscanfRetn;
	sscanfRetn = sscanf(nline, " %d %d ", &p, &q);
	if(sscanfRetn != 1){
		//Error if first line has more than one value
		printf("Error line at 1: Only one value\n");
		exit(1);
	}
	n = p;
	//Create array of nodes, all of them point to NULl
	IntList* adjVertices = (IntList*)calloc(n, sizeof(IntList));
	//max incremented till EOF
	int max = 1;
	for(int i = 0; i<max; i++){
		nline = fgets(line, sizeof(line), file);
	
		//EOF
		if(nline == NULL) break;
		sscanfRetn = sscanf(nline, " %d %d %d ", &p, &q, &wgt);
		//Error if node value is greater than n
		if(p>n){
			printf("Error at line %d: node %d is greater than number of nodes(%d)\n", i+2, p, n);
			exit(1);
		}

		//calls intCons to add intListNode to the array of intList (pointers)
		//returns a pointer (IntList) to the most recent node added to the linked list
		adjVertices[p-1] = intCons(q, adjVertices[p-1]);
		
		//increment m to keep track of total number of edges

		//increment max
		max++;
		//increment total number of edges
		m++;

	}
	return adjVertices;
}

void printIntListNodes(IntList* adjVertices){
	//I used the below function to get the number of digits of the n value in order to have a prettier print.
	//I'm sure I could have written a really complicated amd inefficiant method on my own
	//, but instead I checked out a post from stackoverflow which showed me a really clean way to do it.
	//source url: http://stackoverflow.com/questions/1068849/how-do-i-determine-the-number-of-digits-of-an-integer-in-c
	int width = (int)floor (log10 (abs (n))) + 1; 
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	printf("------------------\n");
	for(int i=0; i<n; i++){
		
		//Create temp variable tp print the linked list of intListNodes
		IntList temp = adjVertices[i];
		
		//if temp at first is NULL then that means the node indexed in the n_array at i+1 
		//does not point(in the sense of directional graph, not pointers) to any nodes
		
		if(temp == NULL){
			//-*d is for the left justification (spacing)
			//The below print function used -*d to left justify each line
			//I checked out a stackoverflow post to learn how to do this
			//source url: http://stackoverflow.com/questions/757627/how-do-i-align-a-number-like-this-in-c
			printf("%-*d     [NULL]\n", width,i+1);
			//continues and goes to next iteration
			continue;
		}	
		//print index+1 of n_array which coincidentally is the value of the node
		printf("%-*d     [", width,i+1);
		//temp varaible used to go through the linked list until it reaches the end(when it's value is NULL)
		while(temp != NULL){
			//if the the node that temp points to has an IntList that points to NULL that means temp has reached the end of the linkwd list
			if(intRest(temp) != NULL){
				//access function to get the value of 'int element, and prints knowing that there are more values left to print'
				printf("%d, ", intFirst(temp));
			}else{
				//access function to get the value of 'int element', and prints knowing that the value comes from the last node in the list
				printf("%d", intFirst(temp));
			}
			//temp is then set to the pointer of the node's IntList that it was pointing to
			temp = intRest(temp);
		}

		printf("]\n");
	}
}

void* loadIntVecGraph(FILE *file){
	char line[2048];
	//Get the first line to get n (number of nodes) or check for an error
	char *nline = fgets(line, sizeof(line), file);
	int p, q, wgt, sscanfRetn;
	sscanfRetn = sscanf(nline, " %d %d ", &p, &q);
	if(sscanfRetn != 1){
		//Error if first line has more than one value
		printf("Error line at 1: Only one value\n");
		exit(1);
	}

 	n = p;

	//Create array of nodes, all of them point to NULl
	IntVec* adjVertices = (IntVec*)calloc(n, sizeof(IntVec));
	//max incremented till EOF
	int max = 1;
	for (int i = 0;  i<n; i++){
		adjVertices[i] = intMakeEmptyVec();
	}

	for(int i = 0; i<max; i++){
		nline = fgets(line, sizeof(line), file);
		
		//EOF
		if(nline == NULL) break;
		sscanfRetn = sscanf(nline, " %d %d %d", &p, &q, &wgt);	
		//Error if node value is greater than n
		if(p>n){
			printf("Error at line %d: node %d is greater than number of nodes(%d)\n", i+2, p, n);
			exit(1);
		}



		//calls intVecPush and adds the q value to adjVertices[p-1]->data
		intVecPush(adjVertices[p-1], q);

		//increment max
		max++;
		//increment total number of edges
		m++;

	}
	return adjVertices;
}

void printIntVecNodes(IntVec* adjVertices){
	//I used the below function to get the number of digits of the n value in order to have a prettier print.
	//I'm sure I could have written a really complicated amd inefficiant method on my own
	//, but instead I checked out a post from stackoverflow which showed me a really clean way to do it.
	//source url: http://stackoverflow.com/questions/1068849/how-do-i-determine-the-number-of-digits-of-an-integer-in-c
	int width = (int)floor (log10 (abs (n))) + 1; 
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	printf("------------------\n");
	for(int i=0; i<n; i++){
		//-*d is for the left justification (spacing)
		//The below print function used -*d to left justify each line
		//I checked out a stackoverflow post to learn how to do this
		//source url: http://stackoverflow.com/questions/757627/how-do-i-align-a-number-like-this-in-c
		printf("%-*d     [", width,i+1);
		//Prints null if there are no values in the intVec->data
		if(adjVertices[i]==NULL){
			printf("NULL");
		}
		else{
			//increments down to 0 from sz-1 in order to print like a stack
			for(int j = intSize(adjVertices[i])-1; j > -1; j--){
				if(j>0){
					printf("%d, ", intData(adjVertices[i], j));	
				}else{
					printf("%d", intData(adjVertices[i], j));	
				}
			}
		}
		printf("]\n");

	}
}

void printAdjVerticesT(IntVec* adjVertices){
	//I used the below function to get the number of digits of the n value in order to have a prettier print.
	//I'm sure I could have written a really complicated amd inefficiant method on my own
	//, but instead I checked out a post from stackoverflow which showed me a really clean way to do it.
	//source url: http://stackoverflow.com/questions/1068849/how-do-i-determine-the-number-of-digits-of-an-integer-in-c


	int width = (int)floor (log10 (abs (n))) + 1; 
	printf("\nTransposed Graph\n");
	printf("n = %d\n", n);
	printf("m = %d\n", m);

	printf("------------------\n");
	for(int i=0; i<n; i++){
		//-*d is for the left justification (spacing)
		//The below print function used -*d to left justify each line
		//I checked out a stackoverflow post to learn how to do this
		//source url: http://stackoverflow.com/questions/757627/how-do-i-align-a-number-like-this-in-c
		printf("%-*d     [", width,i+1);
		//Prints null if there are no values in the intVec->data
		if(adjVertices[i]==NULL){
			printf("NULL");
		}
		else{
			//increments down to 0 from sz-1 in order to print like a stack
			for(int j = intSize(adjVertices[i])-1; j > -1; j--){
				if(j>0){
					printf("%d, ", intData(adjVertices[i], j));	
				}else{
					printf("%d", intData(adjVertices[i], j));	
				}
			}
		}
		printf("]\n");

	}

}

void* loadUndirectedIntVecGraph(FILE *file){
	char line[2048];
	//Get the first line to get n (number of nodes) or check for an error
	char *nline = fgets(line, sizeof(line), file);
	int p, q, wgt, sscanfRetn;
	sscanfRetn = sscanf(nline, " %d %d ", &p, &q);
	if(sscanfRetn != 1){
		//Error if first line has more than one value
		printf("Error line at 1: Only one value\n");
		exit(1);
	}

 	n = p;

	//Create array of nodes, all of them point to NULl
	IntVec* adjVertices = (IntVec*)calloc(n, sizeof(IntVec));
	//max incremented till EOF
	int max = 1;
	for (int i = 0;  i<n; i++){
		adjVertices[i] = intMakeEmptyVec();
	}

	for(int i = 0; i<max; i++){
		nline = fgets(line, sizeof(line), file);
		
		//EOF
		if(nline == NULL) break;
		sscanfRetn = sscanf(nline, " %d %d %d", &p, &q, &wgt);	
		//Error if node value is greater than n
		if(p>n){
			printf("Error at line %d: node %d is greater than number of nodes(%d)\n", i+2, p, n);
			exit(1);
		}



		//calls intVecPush and adds the q value to adjVertices[p-1]->data
		intVecPush(adjVertices[p-1], q);
		intVecPush(adjVertices[q-1], p);

		//increment max
		max++;
		//increment total number of edges
		m++;

	}
	return adjVertices;
}

