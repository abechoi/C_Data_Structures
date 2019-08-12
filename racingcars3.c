
/*
	RACING CARS 3:
	1. Added *prev into RacingCar struct
	2. Added rmCar function to remove the tail node
	3. Improved CLI

	UPCOMING FEATURES:
	1. Add index into RacingCar struct
	2. Add function to remove node by searching index
	3. Implement doubly linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S_RacingCar{

	char name[12];
	int speed;
	int index;
	struct S_RacingCar *next;
	struct S_RacingCar *prev;

} RacingCar;


// PRINT LIST
void printList( RacingCar *start ){

	int count = 0;
	RacingCar *currentCar = start;
	printf("\n%s\n%s\n%s\n",
		"-----------",
		"Printing...",
		"-----------");

	while( currentCar != NULL ){
		++count;

		//printf("Car: %d\nName: %s\nSpeed: %d\n--------\n", 
		//	count, currentCar->name, currentCar->speed );
		printf("%s\n%s%s\n%s%d\n%s\n",
			"-----------",
			"Name: ", currentCar->name,
			"Speed: ", currentCar->speed,
			"-----------");


		currentCar = currentCar->next;
	}
	printf("%s%d\n%s\n%s",
		"TOTAL CARS: ", count,
		"-----------",
		": press [enter] to continue...");
	getchar();

}

// ADD CAR
RacingCar *addCar( RacingCar *previous ){

	char input[16];
	RacingCar *newCar = malloc( sizeof(RacingCar) );

	newCar->prev = previous;

	printf("%s\n%c", "Enter name and speed: [string] [int]", ':');
	fgets( input, 15, stdin );
	sscanf( input, "%s %d", newCar->name, &newCar->speed );


	printf("\n%s\n%s\n%s\n%s%s\n%s%d\n%s\n",
		"--------",
		"Adding...",
		"--------",
		"Name: ", newCar->name,
		"Speed: ", newCar->speed,
		"--------");

	// Only start->prev is null
	if( previous != NULL ){
		previous->next = newCar;
	}

	return newCar;
}

// REMOVE CAR
RacingCar *rmCar( RacingCar *newest ){

	RacingCar *currentCar = newest;

	if( currentCar->prev == NULL ){
		printf("\n%s\n", "Error: Cannot delete the head node..." );
		return currentCar;
	}
	else{

		printf("\n%s%s%s%d%s\n", 
			"Freeing ",newest->name,
			" @ ",newest->speed, " MPH...");
		
		free( newest );
		currentCar = currentCar->prev;
		currentCar->next = NULL;
		
		return currentCar;
	}
}

// CLEAN UP
void cleanUp( RacingCar *start ){

	RacingCar *freeMe = start;
	RacingCar *holdMe = NULL;

	// Hold the address of the next node to prevent losing address
	while( freeMe != NULL ){

		holdMe = freeMe->next; 
		printf("%s%s%s%d%s\n", 
			"Freeing ", freeMe->name,
			" @ ",freeMe->speed, " MPH...");

		free(freeMe);
		freeMe = holdMe;
	}
}

// PRINT MENU
void printMenu(){

	printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%c",
	"-----------",
	"Racing Cars",
	"-----------",
	"a) add cars",
	"r) remove cars",
	"p) print cars ",
	"q) quit",
	"-----------",
	 ':');

}


int main(){

	char input[16];
	char command[16];
	RacingCar *start = NULL;
	RacingCar *newest = NULL;

	printMenu();
	// WHILELOOP1
	while( fgets( input, 15, stdin ) ){

		sscanf( input,"%c", command);

		if( *command == 'q' ){
			printf("\nQuitting...\n\n");
			break;
		}
		else if( *command == 'r' ){
			newest = rmCar(newest);
		}
		else if( *command == 'p' ){
			printList(start);
		}
		else if( *command == 'a' ){

			if( start == NULL ){
				start = addCar(NULL);
				newest = start;
			}
			else{
				newest = addCar(newest);
			}
		}
		printMenu();
	} // END WHILELOOP1

	cleanUp(start);
	return 0;
} // END MAIN

