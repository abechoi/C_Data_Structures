/*
	Youtube: Bluefever Software
	Beginning C Programming - Part 45 - Data Structures & Linked Lists #3 and #4

	RACING CARS:
	1. Use a linked list of racing cars
	2. Create functions to add cars, print list of added cars, and quit

	NEXT OBJECTIVE:
	1. Have user populate the linked list via command line
	2. Delete the hardcoded racing cars
*/

#include <stdio.h>

typedef struct S_RacingCar{

	char name[12];
	int speed;
	struct S_RacingCar *next; // Points to the next car struct

} RacingCar;

void PrintList(RacingCar *start){

	RacingCar *currentCar = start;
	int count = 0;

	while( currentCar != NULL ){
		
		++count;

		printf("Car: %d\nName: %s\nSpeed: %d\n", 
			count, currentCar->name, currentCar->speed );
		currentCar = currentCar->next;
	}
	printf("TOTAL: %d\n", count);

}

int main(){

	RacingCar RedBull = { "RedBull", 100, NULL };
	RacingCar Ferrari = {"Ferrari", 90, NULL};
	RacingCar Mercedes = {"Mercedes", 80, NULL};
	RacingCar Lotus = {"Lotus", 70, NULL};
	RacingCar McLaren = {"McLaren", 60, NULL};

	RedBull.next = &Ferrari;
	Ferrari.next = &Mercedes;
	Mercedes.next = &Lotus;
	Lotus.next = &McLaren;

	PrintList(&RedBull);

	return 0;
}