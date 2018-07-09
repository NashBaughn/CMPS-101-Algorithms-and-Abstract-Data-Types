#include <stdio.h>
#include <stdlib.h>
#include "intVec.h"
#ifndef dfsPhase2
#define dfsPhase2

int dfsSweepT(IntVec* adjVertices, int n, int* color2, int* parent2, IntVec finishStak1, int* finish_times2, int* discover_times2, IntVec finishStak2, int* dfstRoot2);

int dfsT(IntVec* adjVerticesT, int v, int* color2, int* parent2, IntVec finishStak1, int* finish_times2, int* discover_times2, IntVec finishStak2, int* dfstRoot2);

#endif