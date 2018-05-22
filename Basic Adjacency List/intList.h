//Nash Baughn
//cruzId: nbaughn

/* intList.h
 * This header file is needed to be able to use the functions and defintnions from intList.c in graph01.c.
 * In other words, graph01.c has access to intList.c though intList.h (header file).
 */

#ifndef C101IntList
#define C101IntList

/* Multiple typedefs for the same type are an error in C. */
typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * I am confused... what access funcitons? intFirst and intRest? Isn't that question asked for intFirst and intRest individually 
 */

/** first
 * a preconditon is that oldL must be an IntList that is not equal to nil
 */
int intFirst(IntList oldL);

/** rest
 * a preconditon is that oldL must be an IntList that is not equal to nil
 */
IntList intRest(IntList oldL);

/* Constructors
* What is this for?
 */

/** cons
 * Preconditions: none
 * Postconditions: 
	1. returns a pointer to the new object
	2. the pointer (IntList) cannot be equal to nil
	3. first(x) = newE
	4. rest(x) = oldL
	note - I refrenced the book (page 75) for intCons's pre/postconditions
 */
IntList intCons(int newE, IntList oldL);

#endif
 