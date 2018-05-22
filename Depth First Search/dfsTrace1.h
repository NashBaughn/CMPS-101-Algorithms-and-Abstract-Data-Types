#include <stdio.h>
#include <stdlib.h>
#include "intVec.h"
#ifndef dfsTrace1
#define dfsTrace1

IntVec dfsSweep(IntVec* adjVertices, int n, int* color, int* parent, int* finish_times, int* discover_times, IntVec finishStak1);

int dfs(IntVec* adjVertices, int v, int* color, int* parent,  int* finish_times, int* discover_times, IntVec finishStak1);

#endif