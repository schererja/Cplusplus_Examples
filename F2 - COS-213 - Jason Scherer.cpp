/*
Name: Jason Scherer
Course Name: C++ Programming
Course Number: COS-213
Assignment 2:

Create a class that simulates an alarm clock. In this class you should:
	Store time in hours, minutes, and seconds. Note if time is AM or PM. 
	(Hint: You should have separate private members for the alarm and the clock. Do not forget to have a character variable representing AM or PM.)
	
	Initialize the clock to a specified time.

	Allow the clock to increment to the next second. 
	(Hint: You need to take into account things like if the clock's time is 11:59:59 AM and you increment by a second,
		the time will be 12:00:00 PM. You may need to consider some iterated if statements.)

	Set the alarm and have the alarm print out "WAKE UP" when the set time is reached. (Hint:

		You may wish to create a private function that provides the wished-for printout when the alarm

		time is reached and the alarm clock is on.)

	Display the present time.

	Use the class in a program that uses the functions requiring displaying of time and setting of the alarm.

	Include 2 constructors. One constructor should be the default constructor that will initialize the object

		to 12:00:00 AM. The second constructor should take parameters for hours, minutes, seconds, and

		AM/PM. Both constructors will provide the private members with the time. In addition, have both

		constructors set the alarm clock as off. (You will need a Boolean variable that determines whether the

		alarm is on or off). The function or method you use to set the alarm will set the alarm on.
*/

//Includes and namespace
#include <iostream>
#include <string>
using namespace std;

// Clock class
class Clock
{
public:
	Clock();
	Clock(int, int, int, char);
	~Clock();
	int getHours();
	int getMinutes();
	int getSeconds();
	bool getAlarm();
	char getAM_PM();
	void setHours(int);
	void setMinutes(int);
	void setSeconds(int);
	void setAM_PM(char);
	void setAlarm(bool);
	void setAlarmClock(int, int, int, char);
	void displayTime();
	void incrementSecond();
	bool checkAlarm();
	void displayWakeUp();
private:
	int hours;
	int minutes;
	int seconds;
	char am_pm;
	Clock *alarmTime;
	bool alarmSet;
};

// Basic constructor to have a default time
Clock::Clock()
{
	setHours(12);
	setMinutes(0);
	setSeconds(0);
	setAM_PM('A');
	setAlarm(false);
}

// Constructor to set the time
Clock::Clock(int h, int m, int s, char ap) {
	setHours(h);
	setMinutes(m);
	setSeconds(s);
	setAM_PM(ap);
	setAlarm(false);
}

// Deconstructor
Clock::~Clock()
{
}

// Getter for the hours
int Clock::getHours() {
	return hours;
}

// Getter for the Minutes
int Clock::getMinutes() {
	return minutes;
}

// Getter for seconds
int Clock::getSeconds() {
	return seconds;
}

// Getter for am or pm
char Clock::getAM_PM() {
	return am_pm;
}

// Getter for the alarm status
bool Clock::getAlarm() {
	return alarmSet;
}

// Setter for the hours
void Clock::setHours(int h) {
	hours = h;
}

// Setter for the minutes
void Clock::setMinutes(int m) {
	minutes = m;
}

// Setter for the seconds
void Clock::setSeconds(int s) {
	seconds = s;
}

// Setter for the am or pm
void Clock::setAM_PM(char ap) {
	am_pm = ap;
}

// Setter for the alarm
void Clock::setAlarm(bool alarm) {
	alarmSet = alarm;
}

// Way to display the time in the correct format
void Clock::displayTime() {
	if (hours < 10) {
		cout << "0" << hours << ':';
	}
	else {
		cout << hours << ':';
	}
	if (minutes < 10) {
		cout << "0" << minutes << ':';
	}
	else {
		cout << minutes << ':';
	}
	if (seconds < 10) {
		cout << "0" << seconds << ':';
	}
	else {
		cout << seconds << ':';
	}
	if (am_pm == 'A' || am_pm == 'a') {
		cout << "AM" << endl;
	}
	else {
		cout << "PM" << endl;
	}
}

// Increments the seconds and sets them correct if they hit 60 then go to next digit.
void Clock::incrementSecond() {
	seconds++; 
	if (seconds == 60) { 
		minutes++; 
		seconds = 0; 
		if (minutes == 60){ 
			hours++; 
			minutes = 0; 
			if (hours == 12){ 
				if (am_pm == 'A' || am_pm == 'a') 
					am_pm = 'P';
				else { 
					am_pm = 'A'; 
				}
			} 
			if (hours == 13) 
				hours = 1; 
		} 
	} 
}

// Sets the alarm clock
void Clock::setAlarmClock(int h, int m, int s, char a_p) { 
	alarmTime = new Clock(h, m, s, a_p); 
	setAlarm(true);
} 

// Used to check the alarm against the time.
bool Clock::checkAlarm() {
	if (getAlarm() && alarmTime->getHours() == getHours() && alarmTime->getMinutes() == getMinutes() && alarmTime->getSeconds() == getSeconds()){
		setAlarm(false);
		return true;
	} 
	return false;
} 

void Clock::displayWakeUp() {
	cout << "TIME TO GET UP, THIS IS YOUR ALARM!!!! WAKE UP!!" << endl;
}
// Main Function
int main() {
	Clock clk(11, 59, 0, 'A');
	cout << "Present Time: ";
	clk.displayTime();
	cout << endl;
	clk.setAlarmClock(12, 0, 0, 'P');
	while (true) {
		if (clk.checkAlarm()) {
			clk.displayWakeUp();
			break;
		}
		clk.incrementSecond();
		clk.displayTime();
	}
	cout << endl;
	system("pause");
}
