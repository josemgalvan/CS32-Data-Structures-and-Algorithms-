#ifndef RECURSION_H   
#define RECURSION_H
#include <string>


// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int mTimesN(unsigned int m, unsigned int n);
// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
// tallyTheDigits(18838, 8) => 3
// tallyTheDigits (55555, 3) => 0
// tallyTheDigits (0, 0) => 0 or 1 (either if fine)
//
int tallyTheDigits(int num, int digit);
// Returns a string where the same characters next each other in
// string n are separated by "44" (you can assume the input
// string will not have 4’s)
//
// Pseudocode Example:
// foursUp("goodbye") => "go44odbye"
// foursUp("yyuu") => "y44yu44u"
// foursUp("aaaa") => "a44a44a44a"
//
std::string foursUp(std::string n);

// str contains a single pair of parentheses, return a new
// string made of only the parentheses and whatever those
// parentheses contain
//
// Pseudocode Example:
// parentheticallySpeaking("abc(ghj)789") => "(ghj)"
// parentheticallySpeaking ("(x)7") => "(x)"
// parentheticallySpeaking ("4agh(y)") => "(y)"
// parentheticallySpeaking ("4agh()") => "()"
//
std::string parentheticallySpeaking(std::string str);

// Return true if the total of any combination of elements in
// the array a equals the value of the target.
//
// Pseudocode Example:
// totalEclipseOfTheHeart([2, 4, 8], 3, 10) => true
// totalEclipseOfTheHeart ([2, 4, 8], 3, 6) => true
// totalEclipseOfTheHeart ([2, 4, 8], 3, 11) => false
// totalEclipseOfTheHeart ([2, 4, 8], 3, 0) => true
// totalEclipseOfTheHeart ([], 0, 0) => true
//
bool totalEclipseOfTheHeart(const int a[], int size, int
	target);

bool seasonFinale(std::string maze[], int nRows, int nCols,
	int sr, int sc, int er, int ec);

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise


#endif