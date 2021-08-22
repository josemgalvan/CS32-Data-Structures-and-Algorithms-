#include <string>
using namespace std;

//Function Prototypes ///////
int mTimesN(unsigned int m, unsigned int n);
int tallyTheDigits(int num, int digit);
std::string foursUp(std::string n);
std::string parentheticallySpeaking(std::string str);
bool totalEclipseOfTheHeart(const int a[], int size, int target);
bool seasonFinale(std::string maze[], int nRows, int nCols,
	int sr, int sc, int er, int ec);
//END of Function Prototypes //

// Main//

int main()
{
	//cout << "THis main works";
	//cout << endl;
	//string maze[10] = {
	// "XXXXXXXXXX",
	// "X.......@X",
	// "XX@X@@.XXX",
	// "X..X.X...X",
	// "X..X...@.X",
	// "X....XXX.X",
	// "X@X....XXX",
	// "X..XX.XX.X",
	// "X...X....X",
	// "XXXXXXXXXX"
	//};

	//if (seasonFinale(maze, 10, 10, 8, 2, 1, 1))
	//	cout << "Solvable!" << endl;
	//else
	//	cout << "Out of luck!" << endl;

	//const int a[] = { 2, 4, 8 };
	//const int b[1] = {};
	//cout << totalEclipseOfTheHeart(a, 3, 10);
	//cout << totalEclipseOfTheHeart(a, 3, 6);
	//cout << totalEclipseOfTheHeart(a, 3, 11);
	//cout << totalEclipseOfTheHeart(a, 3, 0);
	//cout << totalEclipseOfTheHeart(b, 0, 0);
	//cout << endl;
	//cout << mTimesN(3, 4);
	//cout << endl;
	//cout << mTimesN(5, 6);
	//cout << endl;
	//cout << mTimesN(0, 0);
	//cout << endl;
	//cout << mTimesN(1, 0);
	//cout << endl;
	//cout << endl;
	//cout << parentheticallySpeaking("abc(ghj)789"); // = > "(ghj)"
	//cout << endl;
	//cout << parentheticallySpeaking("(x)7");
	//cout << endl;
	//cout << parentheticallySpeaking("4agh(y)");
	//cout << endl;
	//cout << parentheticallySpeaking("4agh()");
	//cout << endl; cout << endl;
	//cout << endl;
	//cout << foursUp("goodbye");
	//cout << endl;
	//cout << foursUp("yyuu");
	//cout << endl;
	//cout << foursUp("aaaa");
	//cout << endl; cout << endl;
	//cout << endl;
	//cout << tallyTheDigits(143, 4);
	//cout << endl;
	//cout << tallyTheDigits(18838, 8);
	//cout << endl;
	//cout << tallyTheDigits(55555, 3);
	//cout << endl;
	//cout << tallyTheDigits(0, 0);
	//cout << endl;
	return 0;
}
// END of Main 


//FUNCTION Implementations 

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int mTimesN(unsigned int m, unsigned int n)
{
	if (n == 0)
		return 0;
	else
	{
		return m+ mTimesN(m, n - 1);
	}
}
// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
// tallyTheDigits(18838, 8) => 3
// tallyTheDigits (55555, 3) => 0
// tallyTheDigits (0, 0) => 0 or 1 (either if fine)
//
int tallyTheDigits(int num, int digit)
{
	if (num == 0)
	{
		return 0;
	}
	else if (num % 10 == digit)
	return 1 + tallyTheDigits(num / 10, digit);
	else
		return tallyTheDigits(num / 10, digit);
}
// Returns a string where the same characters next each other in
// string n are separated by "44" (you can assume the input
// string will not have 4’s)
//
// Pseudocode Example:
// foursUp("goodbye") => "go44odbye"
// foursUp("yyuu") => "y44yu44u"
// foursUp("aaaa") => "a44a44a44a"
//
std::string foursUp(std::string n)
{
	if (n.size() == 0 || n.size() == 1) //cannot have duplicate letters
		return n;
	else if (n.substr(0, 1) == n.substr(1, 1))
		return(n.substr(0, 1) + "44" + foursUp(n.substr(1, n.size() - 1)));
	else
		return(n.substr(0, 1) + foursUp(n.substr(1, n.size() - 1)));

}
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
std::string parentheticallySpeaking(std::string str)
{
	if (str.substr(0, 1) == "(") //start of what we need
	{
		if (str.substr(str.size() - 1, 1) == ")")
			return str; //this means the whole string is enclosed by parenthesis
		else
			return parentheticallySpeaking(str.substr(0, str.size() - 1));

	}
	else
	return parentheticallySpeaking(str.substr(1, str.size() - 1));
	//dont save the part if it didnt have an opening parenthesis
	//
}
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
	target)
{
	if (size == 0 && target == 0) 
	{
		return true;
	}
	if (size == 0)
	{
		return false; //array has been computed and it didnt equal target	
	}
	if (target == 0)
	{
		return true;
	}
	return totalEclipseOfTheHeart(a+1,size-1,target-a[0]) || totalEclipseOfTheHeart(a + 1, size - 1, target + a[0]); // This is not always correct.
}

bool seasonFinale(std::string maze[], int nRows, int nCols,
	int sr, int sc, int er, int ec)
{
	//how can we know if there is no path??
	//we can track our steps by changing the pathway from ".' to "D" for discovered if at some point we are surroinded by obstacles or D then return false;
	// also want to go back from a dead end so it could go back if next step is "D"
	if (sr == er && sc == ec)
	{
		return true;
	}
	maze[sr][sc] = 'D';
	//rand movement it will get there by chance hopefully
	//else if((maze[sr - 1][sc] != '.' ) && (maze[sr + 1][sc] != '.' )&& (maze[sr][sc - 1] != '.') && (maze[sr][sc + 1] != '.'))
		//return false;
	//case where its trapped in an alley it will go back and forth forever
	//if (maze[sr - 1][sc] == '.' || maze[sr - 1][sc] == 'D' && maze[sr][sc - 1] == '.' || maze[sr][sc - 1] == 'D')
		//return seasonFinale(maze, nRows, nCols, sr - 1, sc, er, ec) || seasonFinale(maze, nRows, nCols, sr, sc - 1, er, ec);
	if (maze[sr + 1][sc] == '.')
		if (seasonFinale(maze, nRows, nCols, sr + 1, sc, er, ec))
			return true;
	if (maze[sr - 1][sc] == '.')
		if (seasonFinale(maze, nRows, nCols, sr - 1, sc, er, ec))
			return true;
	if (maze[sr][sc - 1] == '.')
		if (seasonFinale(maze, nRows, nCols, sr, sc - 1, er, ec))
			return true;
	if (maze[sr][sc + 1] == '.')
		if (seasonFinale(maze, nRows, nCols, sr, sc + 1, er, ec))
			return true;

	return false;
}
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
