#include <string>
using namespace std;

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int prod(unsigned int m, unsigned int n)
{
	if (n == 0)
		return 0;
	return m + prod(m, n - 1);
}


// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
// numberOfDigits(18838, 8) => 3
// numberOfDigits(55555, 3) => 0
// numberOfDigits(0, 0) => 0 or 1 (either if fine)
//
int numberOfDigits(int num, int digit)
{
	if (num == 0)
		return 0;
	else if (num % 10 == digit)
		return 1 + numberOfDigits(num / 10, digit);
	else
		return numberOfDigits(num / 10, digit);
}


// Returns a string where the same characters next each other in
// string n are separated by "22"
//
// Pseudocode Example:
// doubleDouble("goodbye") => "go22odbye"
// doubleDouble("yyuu") => "y22yu22u"
// doubleDouble("aaaa") => "a22a22a22a"
//
string doubleDouble(string n)
//Approach:
//process the string starting from the front:
//if the front letter is the same as the "next" letter, then recurse but also appent "22".
//the base case is when you react the end, with size == 1, which then you return because it's impossible to check a next!
//BOTH the 0 and 1 cases are end cases;
//	- with a passed empty string, should just return the empty string
//	- with a passed 1+ string, return the char
{
	if (n.size() == 0 || n.size() == 1)
		return n;
	//if you even get to this point, this means there are AT LEAST 2 chars in the string
	else if (n.substr(0, 1) == n.substr(1, 1))
		return (n.substr(0, 1) + "22" + doubleDouble(n.substr(1, n.size() - 1)));
	//so, this means that the first and second letters aren't the same, just return the first letter and keep processing the string!
	else return (n.substr(0, 1) + doubleDouble(n.substr(1, n.size() - 1)));
}


/// str contains a single pair of curly brackets, return a new
// string made of only the curly brackets and whatever those
// curly brackets contain
//
// Pseudocode Example:
// curlyFries("abc{ghj}789") => "{ghj}"
// curlyFries("{x}7") => "{x}"
// curlyFries("4agh{y}") => "{y}"
// curlyFries("4agh{}") => "{}"
//
string curlyFries(string str)
//Approach:
//same logic as last time: process the string one by one char
//str has TO AT LEAST HAVE TWO CHARS: "{}"... it's a GIVEN!!!
{
	if (str.substr(0, 1) == "{")
	{
		if (str.substr(str.size() - 1, 1) == "}")
			return str;
		else
			return curlyFries(str.substr(0, str.size() - 1));
	}
	else return curlyFries(str.substr(1, str.size() - 1));
}


// Return true if the total of any combination of elements in
// the array a equals the value of the target.
//
// Pseudocode Example:
// addEmUp([2, 4, 8], 3, 10) => true
// addEmUp([2, 4, 8], 3, 6) => true
// addEmUp([2, 4, 8], 3, 11) => false
// addEmUp({2, 4, 8], 3, 14) => true
// addEmUp([2, 4, 8], 3, 0) => true
// addEmUp([], 0, 0) => true
//
bool addEmUp(const int a[], int size, int target)
{
	if (target == 0)
		return true; // the only way you return true is if the target is 0, meaning your additions add up to the OG target!
	if (size == 0)
		return false; // if you deplete the array, then it's not gonna work
	return (addEmUp(a + 1, size - 1, target - a[0]) || addEmUp(a + 1, size - 1, target));
}


//HELPER for the maze function
void mazeSolver(string maze[], int sr, int sc, int er, int ec, bool& ret)
{
	//"curr" = end, then it's possible!
	if (sr == er && sc == ec)
	{
		ret = true;
		return;
	}
	//drop crumb so we don't recheck where we've been!
	maze[sr][sc] = '#'; //guess it needs to be specifically a char if you want to isolate a index!
	if (maze[sr - 1][sc] == '.')
		mazeSolver(maze, sr - 1, sc, er, ec, ret);
	if (maze[sr + 1][sc] == '.')
		mazeSolver(maze, sr + 1, sc, er, ec, ret);
	if (maze[sr][sc - 1] == '.')
		mazeSolver(maze, sr, sc - 1, er, ec, ret);
	if (maze[sr][sc + 1] == '.')
		mazeSolver(maze, sr, sc + 1, er, ec, ret);
	//if we literally have run through all the recursive calls and nothing returns true,
	//then we've reached a dead end and should go back up a level... in the "last" case,
	//the maze is impossible and thus, we won't have changed ret!!!
	return;
}
// Return true if there is a path from (sr, sc) to (er, ec) through the maze; return false otherwise
// 
// Pseudocode:
// if the start location is equal to the ending location, then we've solved the maze, so return true.
//		mark the "current" (sr, sc) as visited.
//		for each of the possible directions (up, down, left, right)
//			if the location one step in that direction is unvisited and a path (.)
//				then call canWeinish starting from that location with the same (er, ec)
//					if that returns true, then propogate it upwards.
//			if you exhaust all the possibilities, return false.
//
// ***seems that based on the assumptions about the inputs and the way the code is written, 
// we cannot physically end up on an @ or on an X: going OOB is impossible!
bool canWeFinish(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	bool ret = false;
	mazeSolver(maze, sr, sc, er, ec, ret);
	return ret;
}