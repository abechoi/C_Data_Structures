/*
	VA LIST:
	1. I was under the impression that I would be able to enter my arguments 
	while executing the program. Example: ./a.out 3 7 8 9, 3 representing the 
	number of args hence followed by 7 8 9, but I cannot find any examples or
	videos to support this. I wasted a lot of time.

	This is a forbidden jitsu... VA LIST should be used sparingly, usually in 
	cases where a null pointer is being assumed to be an integer.
*/

#include <stdio.h>
#include <stdarg.h>

double average( int num, ... ){

	va_list arguments;
	double sum = 0;

	va_start( arguments, num);

	for( int x = 0; x < sum; ++x ){

		sum += va_arg( arguments, double );
	}
	va_end( arguments );

	return sum / num;
}

int main(){

	printf("%f\n", average( 3, 12.2, 22.3, 4.5 ) );
	printf("%f\n", average( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) );

	return 0;
}









