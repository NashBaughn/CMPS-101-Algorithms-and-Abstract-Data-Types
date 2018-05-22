//nash baughn
//cruzId: nbaughn
#include "intList.h"

//All code in intList.c comes from the JavatoC.pdf file provided.
//The only change is IntListStruct is now IntListNode because that was more intutitive to me

struct IntListNode{
	int element;
	IntList next;
};

//const IntList intNil = NULL;

typedef struct IntListNode IntListNode;

//Access function to get 'int element' from the node
int intFirst(IntList oldL){
	return oldL -> element;
}

//Access function to get the pointer (IntList) to the next node
IntList intRest(IntList oldL){
	return oldL -> next;
}

//Constructor that creates a new node 
IntList intCons(int newElement, IntList oldList){
	IntList newList = calloc(1, sizeof(struct IntListNode));
	newList->element = newElement;
	//Makes the new node point to the first/most receent node in the linked list
	newList->next = oldList;
	//Returns pointer to the new node, new node is now the first/most receent node in the linked list
	return newList;
}

