#include "dfsTrace1.h"

static int time=0;


IntVec dfsSweep(IntVec* adjVertices, int n, int* color, int* parent,  int* finish_times, int* discover_times, IntVec finishStak1){
	



	for(int i = 0; i<n; i++){
		parent[i] = 1;
	}

	int ans = 0;
	
	for(int v = 0; v < n; v++){
		if(color[v] == 0){
			parent[v] = -1;
			int vAns = dfs(adjVertices, v, color, parent, finish_times, discover_times, finishStak1);
		}
	}

	return finishStak1;
}

int dfs(IntVec* adjVertices, int v, int* color, int* parent,  int* finish_times, int* discover_times, IntVec finishStak1){
	if(color[v] != 0){ return 0;}
	int tmp_sz = intSize(adjVertices[v]);

	int w, ans = 0;

	IntVec remAdj = (IntVec)calloc(1, sizeof(IntVec));


	remAdj = adjVertices[v];


	


	color[v] = 1;
	time++;
	discover_times[v] = time;


	while(intSize(remAdj) > 0){
	
		w = intTop(remAdj);
		intVecPop(remAdj);
		
		if(color[w-1]== 0){
			
			int wAns = dfs(adjVertices, w-1, color, parent, finish_times, discover_times, finishStak1);
		}else{
			
		}

	}
	intVecPush(finishStak1, v+1);
	color[v] = 2;
	time++;
	finish_times[v] = time;

	return 0;
}





















