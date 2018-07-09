#include <stdio.h>
#include <stdlib.h>
#include "intList.h"
#include <math.h>


int main( int argc, char *argv[])  {

	FILE *file = NULL;

	if (argc == 1){
		printf("Usage: java graph input.data\n");

	}else{	
		file = fopen(argv[1], "r");
		if (file == NULL){
			printf("Error: Could not find file %s\n", argv[1]);
			exit(1);
		}
	}

	char line[2048];
	//Get the first line to get n (number of nodes) or check for an error
	char *nline = fgets(line, sizeof(line), file);
	

	int p, q, n, m=0;
    int sscanfRetn;

	sscanfRetn = sscanf(nline, " %d %d ", &p, &q);

	if(sscanfRetn != 1){
		//Error if first line has more than one value
		printf("Error line at 1: Only one value\n");
		exit(1);
	}

	n = p;
	
	//Create array of nodes, all of them point to NULl
	IntList* n_array = (IntList*)calloc(n, sizeof(IntList));

	for(int i = 0; i<n; i++){
		nline = fgets(line, sizeof(line), file);
		
		//EOF
		if(nline == NULL) break;
		
		sscanfRetn = sscanf(nline, " %d %d ", &p, &q);
		//Error if node value is greater than n
		if(p>n){
			printf("Error at line %d: node %d is greater than number of nodes(%d)\n", i+2, p, n);
			exit(1);
		}
		//Error if there is more than two values on the line
		if (sscanfRetn != 2){
			printf("Error at line %d: Bad line.\n", i+2);
			exit(1);
		}
		//calls intCons to add intListNode to the array of intList (pointers)
		//returns a pointer (IntList) to the most recent node added tot he linked list
		n_array[p-1] = intCons(q, n_array[p-1]);
		
		//increment m to keep track of total number of edges
		m++;

	}
	//prints number of nodes
	printf("n = %d\n", n);
	//prints number of edges
	printf("m = %d\n", m);

	//I used the below function to get the number of digits of the n value in order to have a prettier print.
	//I'm sure I could have written a really complicated amd inefficiant method on my own
	//, but instead I checked out a post from stackoverflow which showed me a really clean way to do it.
	//source url: http://stackoverflow.com/questions/1068849/how-do-i-determine-the-number-of-digits-of-an-integer-in-c
	int width = (int)floor (log10 (abs (n))) + 1; 

	for(int i=0; i<n; i++){
		//Create temp variable tp print the linked list of intListNodes
		IntList temp = n_array[i];
		//if temp at first is NULL then that means the node indexed in the n_array at i+1 
		//does not point(in the sense of directional graph, not pointers) to any nodes
		if(temp == NULL){
			//-*d is for the left justification (spacing)
			//The below print function used -*d to left justify each line
			//I checked out a stackoverflow post to learn how to do this
			//source url: http://stackoverflow.com/questions/757627/how-do-i-align-a-number-like-this-in-c
			printf("%-*d     null\n", width,i+1);
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

	//success
	return 0;
}













