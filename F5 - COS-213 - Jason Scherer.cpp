/*
Name: Jason Scherer
Course Name: C++ Programming
Course Number: COS-213
Question 5:

Derive the cube class from the base square class. 

Assume the square class has a protected member variable representing the side called side and declared as a double with a default value of 1.0. 

It also has a public function called calcVal that evaluates the area of a square as side * side.

In your derived class have the default values for side be 1. For the cube class include a public function

calcVal that evaluates the volume of the cube. (Hint: The volume of the cube is side * square :: calcVal.)

*/
#include <iostream>
using namespace std;

// Basic Square class to make a square object and be able to calculate area.
class Square
{
public:
	Square();
	Square(double);
	~Square();
	double calcVal();
	void setSide(double);
	double getSide();
protected:
	double side = 1.0;
};

// Basic Constructor
Square::Square()
{
	setSide(0);
}

// Constructor that takes a double for the side.
Square::Square(double s) {
	setSide(s);
}

// Deconstructor for the Square object
Square::~Square()
{
}
// Used to calculate the area.
double Square::calcVal() {
	return side * side;
}

// Setter for the side.
void Square::setSide(double s) {
	side = s;
}

// Getter for the side.
double Square::getSide() {
	return side;
}

// Object to make a cube which derives from Square
class Cube : Square
{
public:
	Cube();
	Cube(double);
	~Cube();
	double calcVal();
	void setSide(double);
	double getSide();
protected:
	double side = 1.0;
};

// Getter for the side variable.
double Cube::getSide() {
	return side;
}

// Setter for the cube and also sets the square side.
void Cube::setSide(double s) {
	side = s;
	Square::setSide(s);
}

// Calculates the area of the cube.
double Cube::calcVal() {
	return getSide() * Square::calcVal();
}

// Basic constructor
Cube::Cube()
{
}

// Constructor that passes a double for the side
Cube::Cube(double s)
{
	setSide(s);
}

// Destructor for the cube object
Cube::~Cube()
{
}

// Main 
int main() {
	double s1 = 2.0;

	cout << "Final Project Number 5\n";
	Square square(s1);

	cout << "Area of square: " << square.calcVal() << "\n" << endl;

	double s2 = 4.0;

	Cube cube(s2);

	cout << "Volume of cube: " << cube.calcVal() << endl;

	system("pause");
}
