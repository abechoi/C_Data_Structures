/*
	Youtube: Bluefever Software
	Beginning C Programming - Part 45 - Data Structures & Linked Lists #3 and #4

	RACING CARS:
	1. Use a linked list of racing cars
	2. Create functions to add cars, print list of added cars, and quit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S_RacingCar{

	char name[12];
	int speed;
	struct S_RacingCar *next; // Points to the next car struct

} RacingCar;


void PrintList(RacingCar *start){
// PrintList function starts by point at the head, printing it,
// then traversing the list to print the rest...

	RacingCar *currentCar = start; // start argument is the current
	int count = 0;
	printf("\nCAR LIST:\n--------\n");

	while( currentCar != NULL ){
		
		++count;

		printf("Car: %d\nName: %s\nSpeed: %d\n--------\n", 
			count, currentCar->name, currentCar->speed );
		currentCar = currentCar->next;
	}
	printf("TOTAL: %d\n", count);

}

RacingCar *addCar(RacingCar *previous){


	printf( "--------\n%s", "Enter name and speed: " );
	char input[16];
	fgets( input, 15, stdin );

	RacingCar *newCar = malloc( sizeof(RacingCar) );
	sscanf( input, "%s %d", newCar->name, &newCar->speed );
	printf("Added: %s\nSpeed: %d\n--------\n", newCar->name, newCar->speed );


	if( previous != NULL ){
		previous->next = newCar;
	}

	return newCar;
}

void cleanUp(RacingCar *start){

	RacingCar *freeMe = start;
	RacingCar *holdMe = NULL;

	while( freeMe != NULL ){
		holdMe = freeMe->next;
		//printf("Added: %s\nSpeed:%d \n", freeMe->name, freeMe->speed);

		printf("%s%s%s%d%s\n",
			"Freeing  ", freeMe->name, " @ ", freeMe->speed, " MPH...");
		free(freeMe);
		freeMe = holdMe;
	}
}

int main(){

	char command[16];
	char input[16];

	RacingCar *start = NULL;	// head
	RacingCar *newest = NULL;	// next

	// WHILELOOP1 - Input commands: quit, print, and add.
	while( fgets( input, 15, stdin) ){ // stdin gives input the command

		sscanf( input, "%s", command ); // command takes input as a string

		// QUIT COMMAND
		if( strncmp( command, "quit", 4 ) == 0 ){
			printf("\n\nQuitting...\n\n");
			break;
		}
		// PRINT COMMAND
		else if( strncmp( command, "print", 5 ) == 0 ){
			PrintList(start);
		}
		// ADD COMMAND
		else if( strncmp( command, "add", 3) == 0 ){
			
			if( start == NULL ){

				start = addCar(NULL); // NULL, head does not have a previous
				newest = start; // head node becomes the start car

			}
			else{

				newest = addCar(newest);
			}
		}

	} // END WHILELOOP1

	cleanUp(start);
	return 0;
}














