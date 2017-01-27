
/*
Name: Jason Scherer
Course Name: C++ Programming
Course Number: COS-213
Assignment 1:

This assignment requires you to code a simulation race between the tortoise and the hare. For this

project, you be using random-number generation to move the creatures. To make things more

interesting, the animals have to race up the side of a slippery mountain, which could cause them to

lose ground. In this race either animal could win or there could be a tie with no clear winner.
*/
#include <string.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// String values for the start and final messages
string hareWon = "The hare won the race, he was the fastest.\n";
string turtleWon = "The slow and stead one won the race.\n";
string aTie = "Oh no they need to race again it was a tie.\n";
string startMessage = "Off they go! A race of a life time.\n";

// Set up global variables
int secondsPassed = 0;
int turtlePosition = 0;
int harePosition = 0;
int turtleMove;
int hareMove;
int turtleMovesByHowMany;
int hareMovesByHowMany;
string raceTrack[70];
int finishedAndWon = 0;
int i;
void clearTrack();
int getMove();
void findTurtleMove(int);
void findhareMove(int);
void printTrackandPosition();

// Clears the track
void clearTrack() {
	for (i = 0; i < 70; i++) {
		raceTrack[i] = "-";
	}
}

// Used to get the move.
int getMove() {
	return 1 + rand() % 10;
}

// Used to find the turtle's move, could be changed at later date without changing main function.
void findTurtleMove(int turtleMove) {
	if (turtleMove >= 1 && turtleMove <= 5) {
		turtleMovesByHowMany = 3;
	}
	else if (turtleMove >= 6 && turtleMove <= 7) {
		turtleMovesByHowMany = -6;
	}
	else {
		turtleMovesByHowMany = 1;
	}
}

// Used to find the hare's move, could be changed at later date without changing main function.
void findhareMove(int hareMove) {
	if (hareMove >= 1 && hareMove <= 2)
		hareMovesByHowMany = 0;
	else if (hareMove >= 3 && hareMove <= 4)
		hareMovesByHowMany = 9;
	else if (hareMove == 5)
		hareMovesByHowMany = -12;
	else if (hareMove >= 6 && hareMove <= 8)
		hareMovesByHowMany = 1;
	else
		hareMovesByHowMany = -2;
}
//  Prints the race track
void printTrackandPosition() {
	for (i = 0; i < 70; i++) {
		printf(raceTrack[i].c_str());
	}
	printf("\n");
}

// Main function
int main() {
	srand(time(NULL));

	printf(startMessage.c_str());

	while (turtlePosition < 70 && harePosition < 70) {
		if (!finishedAndWon) {
			printTrackandPosition();
		}   
		secondsPassed++;
		clearTrack();
		turtleMove = getMove();
		hareMove = getMove();
		findTurtleMove(turtleMove);
		findhareMove(hareMove);
		turtlePosition += turtleMovesByHowMany;
		harePosition += hareMovesByHowMany;
		if (turtlePosition < 0) {
			turtlePosition = 0;
		}
		if (harePosition < 0) {
			harePosition = 0;
		}
		if (turtlePosition > 70) {
			turtlePosition = 70;
		}
		if (harePosition > 70) {
			harePosition = 70;
		}

		raceTrack[turtlePosition] = 'T';
		raceTrack[harePosition] = 'H';

		if (turtlePosition == harePosition) {
			raceTrack[turtlePosition] = "BUMP";
			raceTrack[harePosition] = "BUMP";
		}

		if (turtlePosition >= 70) {
			raceTrack[70] = 'T';
			printf(turtleWon.c_str());
			finishedAndWon = 1;
			system("pause");
			exit(0);
		}
		if (harePosition >= 70) {
			raceTrack[70] = 'H';
			printf(hareWon.c_str());
			finishedAndWon = 1;
			system("pause");
			exit(0);
		}
		system("pause");
	}
}
