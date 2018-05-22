//nash baughn
//cruzId: nbaughn
#include "intList.h"
#include "intVec.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef loadGraph
#define loadGraph

//preconditions: file != NULL
void* loadIntVecGraph(FILE *file);

//preconditions: file != NULL
void* loadIntListGraph(FILE *file);

//preconditions: node_array != NULL
void printIntVecNodes(IntVec* adjVertices);

//preconditions: node_array != NULL
void printIntListNodes(IntList* adjVertices);

void printAdjVerticesT(IntVec* adjVertices);

void* loadUndirectedIntVecGraph(FILE *file);

#endif