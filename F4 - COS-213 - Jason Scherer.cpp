/*
Name: Jason Scherer
Course Name: C++ Programming
Course Number: COS-213
Assignment 4:


Create a template that changes the value of 2 variables. (Hint: Use reference parameters since you
	will swap the variables within the function.) 

Use the template in a program where you change the value of 2 variables of type int and 2 variables of type long.
*/
#include <iostream>

using namespace std;
// Basic template to take two different variables and swap the values;
template <typename T>
void swapValues(T &first_var, T &second_var) {
	T temp = first_var;
	first_var = second_var;
	second_var = temp;
}

int main() {
	//Setting variables
	int a = 4;
	int b = 49;
	long double x = 4.2;
	long double y = 85.2;

	//Use of the template with ints
	swapValues(a, b);
	cout << "Value of a: " << a << "\nValue of b: " << b << endl;

	//Use of the template with doubles
	swapValues(x, y);
	cout << "Value of x: " << x << "\nValue of y: " << y << endl;
	system("pause");
}
