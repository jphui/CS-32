#include "BballRoster.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void myTests()
{
	BballRoster a;

	//Check empty status
	assert(a.rosterEmpty() == true);
	assert(a.howManyPlayers() == 0);
	assert(a.playerOnRoster("Jonathan", "Hui") == false);
	int placeholder = -1;
	assert(a.lookupPlayer("Jonathan", "Hui", placeholder) == false);
	string s1 = "Hi";
	string s2 = "Hello";
	assert(a.choosePlayer(-1, s1, s2, placeholder) == false);
	assert(s1 == "Hi");
	assert(s2 == "Hello");
	assert(placeholder = -1);
	

	//the next 4 test sets focus on adding by last name!


	//adding one person named "AAA BBB" with value "2"
	assert(a.signPlayer("AAA", "BBB", 2) == true);
	assert(a.rosterEmpty() == false);
	assert(a.howManyPlayers() == 1);
	assert(a.playerOnRoster("AAA", "BBB") == true);

	//check to make sure you can't add these manz
	assert(a.signPlayer("AAA", "BBB", 2) == false);
	assert(a.signPlayer("AAA", "BBB", 4) == false);


	//adding a second person named "BBB AAA" with value "1"
	//this specifically tests for "adding at front"
	assert(a.signPlayer("BBB", "AAA", 1) == true);
	assert(a.rosterEmpty() == false);
	assert(a.howManyPlayers() == 2);
	assert(a.playerOnRoster("BBB", "AAA") == true);

	//check to make sure you can't add these manz
	assert(a.signPlayer("BBB", "AAA", 1) == false);
	assert(a.signPlayer("BBB", "AAA", 4) == false);


	//adding a third person named "AAA DDD" with value "4"
	//this specifically tests for "adding at rear"
	assert(a.signPlayer("AAA", "DDD", 4) == true);
	assert(a.rosterEmpty() == false);
	assert(a.howManyPlayers() == 3);
	assert(a.playerOnRoster("AAA", "DDD") == true);

	//check to make sure you can't add these manz
	assert(a.signPlayer("AAA", "DDD", 3) == false);
	assert(a.signPlayer("AAA", "DDD", 4) == false);


	//adding a fourth person named "BBB CCC" with value "3"
	//this specifically tests for "adding between two established nodes"
	assert(a.signPlayer("BBB", "CCC", 3) == true);
	assert(a.rosterEmpty() == false);
	assert(a.howManyPlayers() == 4);
	assert(a.playerOnRoster("BBB", "CCC") == true);

	//check to make sure you can't add these manz
	assert(a.signPlayer("BBB", "CCC", 3) == false);
	assert(a.signPlayer("BBB", "CCC", 4) == false);

	a.dump();


	// need to run same last-name tests


	//adding a fifth person named "AAA AAA" with value "0"
	//this specifically tests for "adding at start based on FIRST name
	assert(a.signPlayer("AAA", "AAA", 0) == true);
	assert(a.rosterEmpty() == false);
	assert(a.howManyPlayers() == 5);
	assert(a.playerOnRoster("AAA", "AAA") == true);

	//check to make sure you can't add these manz
	assert(a.signPlayer("AAA", "AAA", 0) == false);
	assert(a.signPlayer("AAA", "AAA", 4) == false);


	//adding a sixth person named "CCC AAA" with value "11"
	//this specifically tests for "adding at start based on FIRST name
	assert(a.signPlayer("CCC", "AAA", 11) == true);
	assert(a.rosterEmpty() == false);
	assert(a.howManyPlayers() == 6);
	assert(a.playerOnRoster("CCC", "AAA") == true);

	//check to make sure you can't add these manz
	assert(a.signPlayer("CCC", "AAA", 11) == false);
	assert(a.signPlayer("CCC", "AAA", 4) == false);


	//adding a seventh person named "AAA CCC" with value "33"
	//this specifically tests for "adding at start based on FIRST name
	assert(a.signPlayer("AAA", "CCC", 33) == true);
	assert(a.rosterEmpty() == false);
	assert(a.howManyPlayers() == 7);
	assert(a.playerOnRoster("AAA", "CCC") == true);

	//check to make sure you can't add these manz
	assert(a.signPlayer("AAA", "CCC", 33) == false);
	assert(a.signPlayer("AAA", "CCC", 4) == false);

	a.dump();
	

	int setMe = -1;

	// lookupPlayer

	assert(a.lookupPlayer("Jonathan", "Hui", setMe) == false);
	assert(setMe == -1);
	assert(a.lookupPlayer("AAA", "AAA", setMe) == true);
	assert(setMe == 0);
	assert(a.lookupPlayer("CCC", "AAA", setMe) == true);
	assert(setMe == 11);
	assert(a.lookupPlayer("AAA", "DDD", setMe) == true);
	assert(setMe == 4);


	// choosePlayer
	string s3 = "Hep";
	string s4 = "Me";
	assert(a.choosePlayer(-1, s3, s4, setMe) == false);
	assert(s3 == "Hep");
	assert(s4 == "Me");
	assert(setMe == 4); //4 = last value from last test set
	assert(a.choosePlayer(0, s3, s4, setMe) == true);
	assert(s3 == "AAA");
	assert(s4 == "AAA");
	assert(setMe == 0);
	assert(a.choosePlayer(5, s3, s4, setMe) == true);
	assert(s3 == "BBB");
	assert(s4 == "CCC");
	assert(setMe == 3);
	assert(a.choosePlayer(6, s3, s4, setMe) == true);
	assert(s3 == "AAA");
	assert(s4 == "DDD");
	assert(setMe == 4);
	assert(a.choosePlayer(7, s3, s4, setMe) == false);
	assert(s3 == "AAA");
	assert(s4 == "DDD");
	assert(setMe == 4);


	//resignPlayer

	assert(a.resignPlayer("Jonathan", "Hui", 5) == false);
	assert(a.resignPlayer("AAA", "AAA", 100) == true);
	assert(a.lookupPlayer("AAA", "AAA", setMe) == true);
	assert(setMe == 100);
	assert(a.resignPlayer("AAA", "CCC", 200) == true);
	assert(a.lookupPlayer("AAA", "CCC", setMe) == true);
	assert(setMe == 200);
	assert(a.resignPlayer("AAA", "DDD", 300) == true);
	assert(a.lookupPlayer("AAA", "DDD", setMe) == true);
	assert(setMe == 300);


	//signOrResignPlayer

	//signing case!
	assert(a.signOrResign("DDD", "DDD", 999) == true);
	assert(a.howManyPlayers() == 8);

	//resigning case!

	assert(a.signOrResign("DDD", "DDD", 99) == true);
	assert(a.howManyPlayers() == 8);

	a.dump();

	
	//renouncePlayer

	assert(a.renouncePlayer("Jonathan", "Hui") == false);
	assert(a.renouncePlayer("AAA", "AAA") == true);
	assert(a.playerOnRoster("AAA", "AAA") == false);
	assert(a.howManyPlayers() == 7);
	assert(a.renouncePlayer("AAA", "CCC") == true);
	assert(a.playerOnRoster("AAA", "CCC") == false);
	assert(a.howManyPlayers() == 6);
	assert(a.renouncePlayer("DDD", "DDD") == true);
	assert(a.playerOnRoster("DDD", "DDD") == false);
	assert(a.howManyPlayers() == 5);

	a.dump();


	//copy constructor test!
	cerr << "Now for a COPY to be made and printed!" << endl;
	BballRoster b(a);
	b.dump();


	/*
	b and a should be:
	BBB AAA 1
	CCC AAA 11
	AAA BBB 2
	BBB CCC 3
	AAA DDD 300
	*/


	//checkRoster
	/*
			Nombre		Search
			J J		+	J J		==> don't remove
			J J		+	* J		==> don't remove
			J J		+	J *		==> don't remove
			J J		+	* *		==> don't remove

			J C		+	J J		==> remove
			J C		+	* J		==> remove
			J C		+	J *		==> don't remove
			J C		+	* *		==> don't remove

			C J		+	J J		==> remove
			C J		+	* J		==> don't remove
			C J		+	J *		==> remove
			C J		+	* *		==> don't remove

			C C		+	J J		==> remove
			C C		+	* J		==> remove
			C C		+	J *		==> remove
			C C		+	* *		==> don't remove

			4 different search cases = we will have 4 separate BballRosters
	*/

	BballRoster exactName;
	BballRoster starLast;
	BballRoster firstStar;
	BballRoster starStar;

	checkRoster("BBB", "AAA", b, exactName);
	cerr << "checkRoster for an exact match" << endl;
	exactName.dump();
	cerr << "This should read:" << endl;
	cerr << "BBB AAA 1" << endl;

	checkRoster("*", "AAA", b, starLast);
	cerr << "checkRoster for a star, then a last name" << endl;
	starLast.dump();
	cerr << "This should read:" << endl;
	cerr << "BBB AAA 1" << endl;
	cerr << "BBB CCC 11" << endl;

	checkRoster("AAA", "*", b, firstStar);
	cerr << "checkRoster for first name, then a star" << endl;
	firstStar.dump();
	cerr << "This should read:" << endl;
	cerr << "AAA BBB 2" << endl;
	cerr << "AAA DDD 300" << endl;

	checkRoster("*", "*", b, starStar);
	cerr << "checkRoster for both stars" << endl;
	starStar.dump();
	cerr << "This should read:" << endl;
	cerr << "BBB AAA 1" << endl;
	cerr << "CCC AAA 11" << endl;
	cerr << "AAA BBB 2" << endl;
	cerr << "BBB CCC 3" << endl;
	cerr << "AAA DDD 300" << endl;


	//joinRosters
	///moved to another tet case

	cerr << endl << endl;
}

void test1()
{
	BballRoster lakers;
	lakers.signPlayer("LeBron", "James", 6);
	lakers.signPlayer("Anthony", "Davis", 23);
	lakers.signPlayer("Kyle", "Kuzma", 0);
	lakers.signPlayer("Boogie", "Cousins", 15);
	lakers.signPlayer("Rajon", "Rondo", 8);
	for (int n = 0; n < lakers.howManyPlayers(); n++)
	{
		string first;
		string last;
		int val;
		lakers.choosePlayer(n, first, last, val);
		cerr << first << " " << last << " " << val << endl;
	}

	cerr << endl << "This should read:" << endl;
	cerr << "Boogie Cousins 15" << endl;
	cerr << "Anthony Davis 23" << endl;
	cerr << "LeBron James 6" << endl;
	cerr << "Kyle Kuzma 0" << endl;
	cerr << "Rajon Rondo 8" << endl;

	cerr << endl << "Test 1 complete" << endl << endl;
}

void test2()
{
	BballRoster clippers;

	clippers.signPlayer("Tyrone", "Wallace", -1);
	assert(!clippers.playerOnRoster("", ""));
	clippers.signPlayer("Kawhi", "Leonard", -1);
	clippers.signPlayer("", "", -1);
	clippers.signPlayer("Paul", "George", -1);
	assert(clippers.playerOnRoster("", ""));
	clippers.renouncePlayer("Tyrone", "Wallace");
	assert(clippers.howManyPlayers() == 3 && clippers.playerOnRoster("Kawhi", "Leonard") && clippers.playerOnRoster("Paul", "George") && clippers.playerOnRoster("", ""));

	cerr << endl << "Test 2 complete" << endl << endl;
}

void test3()
{
	BballRoster x;
	
	assert(x.signPlayer("Kevin", "Durant", 7));
	assert(x.signPlayer("Kyrie", "Irving", 11));
	assert(x.signPlayer("DeAndre", "Jordan", 6));

	BballRoster y;

	assert(y.signPlayer("Spencer", "Dinwiddie", 8));
	assert(y.signPlayer("Kevin", "Durant", 7));

	BballRoster z;

	assert(joinRosters(x, y, z) == true);
	z.dump();
	cerr << "This should read:" << endl;
	cerr << "Spencer Dinwiddie 8" << endl;
	cerr << "Kevin Durant 7" << endl;
	cerr << "Kyrie Irving 11" << endl;
	cerr << "DeAndre Jordan 6" << endl << endl;


	BballRoster r;

	assert(r.signPlayer("Spencer", "Dinwiddie", 8));
	assert(r.signPlayer("Kevin", "Durant", 35));

	assert(joinRosters(x, r, z) == false);
	z.dump();
	cerr << "This should read:" << endl;
	cerr << "Spencer Dinwiddie 8" << endl;
	cerr << "Kyrie Irving 11" << endl;
	cerr << "DeAndre Jordan 6" << endl << endl;


	cerr << endl << "joinRosters complete" << endl << endl;
}


int main()
{
	myTests(); //memleak is its own file because of fileType
	test1();
	test2();
	test3();

	//test same-list cases!!!
	///gonna assume this works since he basically gave the answer of using assignment operator!

	cerr << "REMOVE DEBUGGING CODE!!! Change SomeType to string?" << endl << endl;
}
