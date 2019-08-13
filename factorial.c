/*
	FACTORIALS:
	1. More recusion practice
	2. Took about 2 hours to figure out how to make this program

	CHALLENGES:
	1. Making use of a single variable - I kept wanting to create more variables so hold data
	but it was getting too crazy.

	NOTES:
	It is very important to know that in this program, "count =" does not get a value until
	all the recusive methods are completed and are returning...
*/

#include <stdio.h>

int factorial( int count ){

	if(count <= 1){ return count; }
	else{ count = count * factorial(count-1); }

	return count;
}

int main(){

	int x;

	printf( "%s\n%c", "Enter number for factorial",':' );
	scanf( "%d" , &x );

	printf( "%d%s%d\n", x, "! = " , factorial(x) );

	return 0;
}