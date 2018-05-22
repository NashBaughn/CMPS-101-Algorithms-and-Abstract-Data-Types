//nash baughn
//cruzId: nbaughn
#include "intVec.h"
#include <stdio.h>
#include <stdlib.h>

struct IntVecNode{
	int* data;
	int capacity;
	int sz;
};

typedef struct IntVecNode IntVecNode;

//returns most recent value added to myVec->data
int intTop(IntVec myVec){
	if(myVec->sz<1){
		
		printf("hey! There is no data\n");
		exit(1);
	}else{
		return myVec->data[myVec->sz-1];
	}

}

//returns value at i-th indicie of myVec->data[]
int intData(IntVec myVec, int i){
	return myVec->data[i];
}

//returns value of size (myVec->sz)
int intSize(IntVec myVec){
	return myVec->sz;
}

//return value of capacity (myVec->capacity)
int intCapacity(IntVec myVec){
	return myVec->capacity;
}

//create empty intVecNode with initial capacity = 4
IntVec intMakeEmptyVec(void){
	IntVec newVec = (IntVec)calloc(1, sizeof(struct IntVecNode));
	//calloc data
	newVec->data = (int*)calloc(intInitCap, sizeof(int));
	newVec->sz = 0;
	newVec->capacity = intInitCap; 

	return newVec;
}

IntVec intMakeEmptyVecN(int np1){
	IntVec newVec = (IntVec)calloc(1, sizeof(struct IntVecNode));
	//calloc data
	newVec->data = (int*)calloc(intInitCap, sizeof(int));
	newVec->sz = 0;
	newVec->capacity = np1; 

	return newVec;
}

//addes a new value to myVec->data and if myVec->sz+1 > myVec->capacity then the array 
//size is doubled using realloc
void intVecPush(IntVec myVec, int newE){	
	
	if(myVec->sz+1 > myVec->capacity){
		int newCap = 2*myVec->capacity;
		int* newData = realloc(myVec->data, newCap*sizeof(int));
		if(newData != myVec->data){

			myVec->data = newData;
		}
		myVec->capacity = newCap;
	}
	
	myVec->sz = myVec->sz+1;
	myVec->data[myVec->sz-1] = newE;
}

//decreases the size of myVec by 1, but checks to makes sure size >= 0
void intVecPop(IntVec myVec){
	if(myVec->sz>0){
		myVec->sz = myVec->sz-1;
	}else{
		printf("size cannot be less than 0\n");
	}	
}

IntVec* transposeGraph(IntVec* oldGraph, int n){
	IntVec* newGraph = (IntVec*)calloc(n, sizeof(IntVec));

	for (int i = 0;  i<n; i++){
		newGraph[i] = intMakeEmptyVec();
	}
	
	for(int v = 0; v<n; v++){	
		for(int i=0; i<intSize(oldGraph[v]); i++){
			intVecPush(newGraph[intData(oldGraph[v], i) -1], v+1);
		}	
	}
	return newGraph;

}





