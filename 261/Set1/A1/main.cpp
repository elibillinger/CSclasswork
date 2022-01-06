/* CSCI 261 Assignment 1:
 * Hello World and ASCII Art
 *
 * Author: Eli Billinger
 *
 * Create a ASCII Smiley Face and give three facts about myself
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants or global variables below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  //******** INSERT YOUR CODE BELOW HERE ********

  //Part 1 ASCII Smiley Face
  cout << "      _____ " << endl;
  cout << "    .'     '." << endl;
  cout << "   /  o   o  \\ " << endl;
  cout << "  |           |" << endl;
  cout << "  |  \\     /  | " << endl;
  cout << "   \\  '---'  / " << endl;
  cout << "    '._____.'  " << endl;

  // Part 2 Facts
  int age = 19;
  int dogs = 2;
  float sleep = 9.5;
  cout << "Hello World!" << endl;
  cout << "I am " << age << " years old." << endl;
  cout << "I have " << dogs << " puppies at home." << endl;
  cout << "I sleep about " << sleep << " hours a night." << endl;
  cout << "Goodbye!" << endl;
  //******** INSERT YOUR CODE ABOVE HERE ********

  // signals the operating system that our program ended OK.
  return 0;
}