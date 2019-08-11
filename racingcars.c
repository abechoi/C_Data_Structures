#include <stdio.h>
#include <string.h>

typedef struct S_RacingCar{

	char name[8];
	int speed;

} RacingCar; // typedef alias

// Print list of cars added by user
void printList(RacingCar carArray[], int num){
	printf("\nCAR LIST:\n--------\n");
	int carIndex = 0;
	RacingCar *car;

	for(carIndex = 0; carIndex < num; ++carIndex){
		
		car = &carArray[carIndex];

		printf("Car: %d\nName: %s\nSpeed: %d\n--------\n",
			carIndex+1,
			car->name,		//carArray[carIndex].name,
			car->speed );	//carArray[carIndex].speed );
	}
	printf("TOTAL: %d\n", num);
}

// RacingCar *car is the memory address of 
int addCar(RacingCar *car){
	
	printf( "%p\n", car );
	printf( "%s", "Enter name and speed: " );
	char input[16];
	fgets( input, 15, stdin );

	int ok = 0; // sentinel, return 1 if car is added

	// breaks input into 2 variables: a string and int
	int result = sscanf( input, "%s %d", car->name, &car->speed );

	// if there are 2 variables, result = 2.
	if( result == 2){

		ok = 1;
		printf("Added: %s \t Speed: %d \n", car->name, car->speed );

	}
	else{
		printf("Sorry, error parsing input\n\n");
	}

	return ok;
} // END addCar()

const int maxCars = 4;

int main(){

	RacingCar allCars[maxCars];
	int numCars = 0;

	char command[16];
	char input[16];

	// Prompt user for string command: print, add, or quit
	while( fgets( input, 15, stdin )){

		// Command variable takes input variable as a string
		sscanf( input, "%s", command );

		// QUIT COMMAND
		if( strncmp( command, "quit", 4) == 0){
			printf("\n\nBreaking...\n");
			break;
		}
		// PRINT COMMAND
		else if( strncmp( command, "print", 5) == 0){
			printList(allCars, numCars);
		}
		// ADD COMMAND
		else if( strncmp( command, "add", 3) == 0){

			if(numCars < maxCars){

				// addCar() returns 1 if car is added...
				// then int numCars is increased by 1
				printf("%p\n", &allCars[numCars]);
				numCars += addCar( &allCars[numCars]);
			}
			else{
				printf("Sorry, list is full!\n");
			}
		}
	}

	
	return 0;
}






