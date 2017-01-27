/*
Name: Jason Scherer
Course Name: C++ Programming
Course Number: COS-213
Assignment 3:

Write a program that reads from the external file input.txt, counts the letters in every word, replaces
the word by that number, and then writes the numbers to an external file output.txt

(Note: Do not forget to copy the blanks. You may wish to use infile.get and outfile.put in your program.) 

Also you may wish to use the strlen( ) function.
*/


#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// main execution method
int main()
{
	// Variables used
	char c;
	ifstream infile;
	ofstream outfile;
	int count = 0;

	cout << "Final Project Problem 3.\n\n"
		<< "This program will replace words with numbers in the output file of the length of the word.";
	//Opens the input file
	infile.open("input.txt");
	if (!infile){
		cerr << "Could not open input.txt" << endl;
		exit(EXIT_FAILURE);
	}
	//Open the output file
	outfile.open("output.txt", ofstream::out);
	if (!infile){
		cerr << "Could not open output.txt" << endl;
		exit(EXIT_FAILURE);
	}
	//Loads file and while it is good keeps the loop going
	while (infile.good())
	{
 		c = infile.get();
		cout << c;
		//If there is a space, new line or tab output them and set count to zero.
		if (c == ' ' ||
			c == '\n' ||
			c == '\t') {
			//Prints to output file
   			outfile << count << c;
   			count = 0;
		}
		//If it isn't a tab, new line, or a space add to the counter
		if (c != ' ' ||
			c != '\n' ||
			c != '\t' ) {
			count++;
		}
	}     

	return 0;
}

