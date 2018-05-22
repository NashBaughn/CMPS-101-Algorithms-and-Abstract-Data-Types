OBJS = intList.o graph01.o
LFLAGS = -g -O0 -Wall -Wextra
CFLAGS = $(LFLAGS) -c 

all: graph01

graph01: $(OBJS)
	gcc $(LFLAGS) $(OBJS) -o graph01

graph01.o: graph01.c
	gcc $(CFLAGS) graph01.c

intList.o: intList.c
	gcc $(CFLAGS) intList.c