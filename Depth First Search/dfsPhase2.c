#include "dfsPhase2.h"

static int timeT=0;


int dfsSweepT(IntVec* adjVerticesT, int n, int* color2, int* parent2, IntVec finishStak1, int* finish_times2, int* discover_times2, IntVec finishStak2, int* dfstRoot2){
	//iterate through parent2 in order assign all values to 1 because it will change to -1 IF it is a root
	for(int i = 0; i<n; i++){
		parent2[i] = 1;
	}

	int ans = 0;
	
	while(intSize(finishStak1)>0){
		int v =  intTop(finishStak1);
		intVecPop(finishStak1);
		if(color2[v] == 0){
			parent2[v] = -1;

			int vAns = dfsT(adjVerticesT, v-1, color2, parent2, finishStak1, finish_times2, discover_times2, finishStak2, dfstRoot2);
		}
	}

	return ans; 
}

int dfsT(IntVec* adjVerticesT, int v, int* color2, int* parent2, IntVec finishStak1, int* finish_times2, int* discover_times2, IntVec finishStak2, int* dfstRoot2){
	if(color2[v] != 0){ return 0;}

	int tmp_sz = intSize(adjVerticesT[v]);

	int w, ans = 0;

	IntVec remAdj = (IntVec)calloc(1, sizeof(IntVec));

	remAdj = adjVerticesT[v];

	color2[v] = 1;
	timeT++;

	discover_times2[v] = timeT;
	dfstRoot2[v-1] = v+1;

	while(intSize(remAdj) > 0){

		w = intTop(remAdj);
		intVecPop(remAdj);
		
		if(color2[w-1]== 0){
			int wAns = dfsT(adjVerticesT, w-1, color2, parent2, finishStak1, finish_times2, discover_times2, finishStak2, dfstRoot2);
		}else{
		}

	}
	
	intVecPush(finishStak2, v+1);
	color2[v] = 2;

	timeT++;
	finish_times2[v] = timeT;
	

	return 0;
}






















