/*
	RECURSION:
	1. Just a quick tutorial on recursions
	2. recursion() function calls the recursion() function until count reaches 10
*/

#include <stdio.h>

void recursion( int count ){

	printf( "%s%d\n", "Recursion count: ", count );

	// base case aka sentinel
	if(count < 10){ recursion(++count); }
}

int main(){

	recursion(1);

	return 0;
}