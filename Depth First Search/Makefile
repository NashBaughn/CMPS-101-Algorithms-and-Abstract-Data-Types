#nash baughn
#cruzId: nbaughn
OBJS = edgeVec.o loadGraph.o greedy04.o minPQ.o
LFLAGS = -g -O0 -Wall -Wextra 
CFLAGS = $(LFLAGS) -c 
CC = gcc

greedy04: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o scc3

edgeVec.o: edgeVec.c edgeVec.h
	$(CC) $(CFLAGS) edgeVec.c

minPQ.o: minPQ.c minPQ.h
	$(CC) $(CFLAGS) minPQ.c

loadGraph.o: loadGraph.c loadGraph.h
	$(CC) $(CFLAGS) loadGraph.c



