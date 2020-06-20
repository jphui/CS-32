#include <cassert> //REMOVE!!!
#include <iostream> //REMOVE!!!

int main()
{
	//prod
	assert(prod(4, 3) == 12);
	assert(prod(4, 0) == 0);
	assert(prod(0, 4) == 0);
	assert(prod(0, 0) == 0);
	assert(prod(1, 4) == 4);
	assert(prod(4, 1) == 4);


	//numberOfDigits
	assert(numberOfDigits(18838, 8) == 3);
	assert(numberOfDigits(55555, 3) == 0);
	assert(numberOfDigits(55555, 5) == 5);
	assert(numberOfDigits(00000, 0) == 0 || numberOfDigits(00000, 0) == 1);
	assert(numberOfDigits(0, 0) == 0 || numberOfDigits(0, 0) == 1);
	assert(numberOfDigits(18838, 1) == 1);
	assert(numberOfDigits(13331, 1) == 2);
	assert(numberOfDigits(0001, 0) == 0);
	assert(numberOfDigits(0001, 1) == 1);


	//doubleDouble
	assert(doubleDouble("goodbye") == "go22odbye");
	assert(doubleDouble("yyuu") == "y22yu22u");
	assert(doubleDouble("aaaa") == "a22a22a22a");
	assert(doubleDouble("godbye") == "godbye");
	assert(doubleDouble("g") == "g");
	assert(doubleDouble("gg") == "g22g");


	//curlyFries
	assert(curlyFries("abc{ghj}789") == "{ghj}");
	assert(curlyFries("{x}7") == "{x}");
	assert(curlyFries("4agh{y}") == "{y}");
	assert(curlyFries("4agh{}") == "{}");
	assert(curlyFries("{}") == "{}");
	assert(curlyFries("{}ass") == "{}");
	assert(curlyFries("{NASDAQ}") == "{NASDAQ}");
	assert(curlyFries("a{ass}") == "{ass}");
	assert(curlyFries("{ass}a") == "{ass}");
	assert(curlyFries("a{ass}a") == "{ass}");


	//addEmUp
	int arr1[3] = { 2, 4, 8 };

	int arr2[2] = { 2, 4 };

	int arr3[1] = { 2 };

	int zero[1] = { -999 }; // when we pass this, we pass size 0 to clarify that this is replicating an empty array!

	int bigArr[6] = { 1,2,3,4,5,6 };

	assert(addEmUp(arr1, 3, 10) == true);
	assert(addEmUp(arr1, 3, 6) == true);
	assert(addEmUp(arr1, 3, 11) == false);
	assert(addEmUp(arr1, 3, 14) == true);
	assert(addEmUp(arr1, 3, 0) == true);
	assert(addEmUp(arr1, 3, 12) == true);

	assert(addEmUp(arr2, 2, 6) == true);
	assert(addEmUp(arr2, 2, 2) == true);
	assert(addEmUp(arr2, 2, 4) == true);
	assert(addEmUp(arr2, 2, 0) == true);
	assert(addEmUp(arr2, 2, 3) == false);

	assert(addEmUp(arr3, 1, 2) == true);
	assert(addEmUp(arr3, 1, 0) == true);
	assert(addEmUp(arr3, 1, 4) == false);
	assert(addEmUp(arr3, 1, 3) == false);

	assert(addEmUp(zero, 0, 0) == true);
	assert(addEmUp(zero, 0, 3) == false);

	assert(addEmUp(bigArr, 6, 12) == true);
	assert(addEmUp(bigArr, 6, 1) == true);
	assert(addEmUp(bigArr, 6, 2) == true);
	assert(addEmUp(bigArr, 6, 3) == true);
	assert(addEmUp(bigArr, 6, 4) == true);
	assert(addEmUp(bigArr, 6, 5) == true);
	assert(addEmUp(bigArr, 6, 6) == true);
	assert(addEmUp(bigArr, 6, 14) == true);
	assert(addEmUp(bigArr, 6, 8) == true);
	assert(addEmUp(bigArr, 6, 100) == false);


	//canWeFinish
	string m1a[5] = { //r = 5, c = 7
					 "XXXXXXX",
					 "X...X@X",
					 "XXX.X.X",
					 "X@....X",
					 "XXXXXXX" };
	string m1b[5] = { //r = 5, c = 7
					 "XXXXXXX",
					 "X...X@X",
					 "XXX.X.X",
					 "X@....X",
					 "XXXXXXX" };
	string m1c[5] = { //r = 5, c = 7
					 "XXXXXXX",
					 "X...X@X",
					 "XXX.X.X",
					 "X@....X",
					 "XXXXXXX" };
	string m1d[5] = { //r = 5, c = 7
					 "XXXXXXX",
					 "X...X@X",
					 "XXX.X.X",
					 "X@....X",
					 "XXXXXXX" };
	string m1e[5] = { //r = 5, c = 7
					 "XXXXXXX",
					 "X...X@X",
					 "XXX.X.X",
					 "X@....X",
					 "XXXXXXX" };

	string m2a[10] = { //r = 10, c = 10
						"XXXXXXXXXX",
						"X.......@X",
						"XX@X@@.XXX",
						"X..X.X...X",
						"X..X...@.X",
						"X....XXX.X",
						"X@X....XXX",
						"X..XX.XX.X",
						"X...X....X",
						"XXXXXXXXXX" };
	string m2b[10] = { //r = 10, c = 10
						"XXXXXXXXXX",
						"X.......@X",
						"XX@X@@.XXX",
						"X..X.X...X",
						"X..X...@.X",
						"X....XXX.X",
						"X@X....XXX",
						"X..XX.XX.X",
						"X...X....X",
						"XXXXXXXXXX" };
	string m2c[10] = { //r = 10, c = 10
						"XXXXXXXXXX",
						"X.......@X",
						"XX@X@@.XXX",
						"X..X.X...X",
						"X..X...@.X",
						"X....XXX.X",
						"X@X....XXX",
						"X..XX.XX.X",
						"X...X....X",
						"XXXXXXXXXX" };
	string m2d[10] = { //r = 10, c = 10
						"XXXXXXXXXX",
						"X.......@X",
						"XX@X@@.XXX",
						"X..X.X...X",
						"X..X...@.X",
						"X....XXX.X",
						"X@X....XXX",
						"X..XX.XX.X",
						"X...X....X",
						"XXXXXXXXXX" };
	string m2e[10] = { //r = 10, c = 10
						"XXXXXXXXXX",
						"X.......@X",
						"XX@X@@.XXX",
						"X..X.X...X",
						"X..X...@.X",
						"X....XXX.X",
						"X@X....XXX",
						"X..XX.XX.X",
						"X...X....X",
						"XXXXXXXXXX" };
	string m2f[10] = { //r = 10, c = 10
						"XXXXXXXXXX",
						"X.......@X",
						"XX@X@@.XXX",
						"X..X.X...X",
						"X..X...@.X",
						"X....XXX.X",
						"X@X....XXX",
						"X..XX.XX.X",
						"X...X....X",
						"XXXXXXXXXX" };

	string m3a[4] = { //r = 4, c = 4
						"XXXX",
						"X.@X",
						"X@.X",
						"XXXX" };
	string m3b[4] = { //r = 4, c = 4
						"XXXX",
						"X.@X",
						"X@.X",
						"XXXX" };

	assert(canWeFinish(m1a, 5, 7, 1, 1, 3, 5) == true);
	cout << "m1a" << endl;
	assert(canWeFinish(m1b, 5, 7, 1, 1, 1, 2) == true);
	cout << "m1b" << endl;
	assert(canWeFinish(m1c, 5, 7, 1, 1, 2, 3) == true);
	cout << "m1c" << endl;
	assert(canWeFinish(m1d, 5, 7, 1, 1, 2, 5) == true);
	cout << "m1d" << endl;
	assert(canWeFinish(m1e, 5, 7, 1, 1, 3, 2) == true);
	cout << "m1e" << endl;

	assert(canWeFinish(m2a, 10, 10, 1, 1, 8, 8) == true);
	cout << "m2a" << endl;
	assert(canWeFinish(m2b, 10, 10, 1, 1, 5, 8) == true);
	cout << "m2b" << endl;
	assert(canWeFinish(m2c, 10, 10, 1, 1, 8, 1) == false);
	cout << "m2c" << endl;
	assert(canWeFinish(m2d, 10, 10, 1, 1, 7, 8) == true);
	cout << "m2d" << endl;
	assert(canWeFinish(m2e, 10, 10, 6, 4, 1, 1) == true);
	cout << "m2e" << endl;
	assert(canWeFinish(m2f, 10, 10, 1, 1, 6, 4) == true);
	cout << "m2f" << endl;

	assert(canWeFinish(m3a, 4, 4, 1, 1, 2, 2) == false);
	cout << "m3a" << endl;
	assert(canWeFinish(m3b, 4, 4, 1, 1, 1, 1) == true);
	cout << "m3b" << endl;


	cout << "REMOVE DEBUGGING CODE!!!" << endl;
}