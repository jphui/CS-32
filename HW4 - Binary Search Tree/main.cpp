#include "WordTree.h"
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

void test1()
{
	cerr << "TEST 1 ---------------------------------" << endl;
	WordTree k;

	k.add("Kim");
	k.add("Kanye");
	k.add("Kanye");
	k.add("Kanye");
	cerr << k << endl;
	assert(k.distinctWords() == 2);
	assert(k.totalWords() == 4);
}

void test2()
{
	cerr << "TEST 2 ---------------------------------" << endl;
	WordTree w;

	w.add("Harry");
	w.add("Niall");
	w.add("Niall");
	w.add("Liam");
	w.add("Louis");
	w.add("Harry");
	w.add("Niall");
	w.add("Zayn");
	cerr << w << endl;

	cerr << "This should be the same as:" << endl;

	WordTree copy = w;
	cerr << copy << endl;
}

void test3()
{
	cerr << "TEST 3 ---------------------------------" << endl;
	WordTree me;

	me.add("Justin");
	me.add("Tim");
	me.add("Tim");
	me.add("Zack");
	me.add("Chengye");
	me.add("Tim");
	assert(me.distinctWords() == 4);
	assert(me.totalWords() == 6);

	cerr << me << endl;

	WordTree copy;
	cerr << copy << endl;
	cerr << "^^^ this should be an empty line because our copy is empty right now" << endl;

	copy = me;

	cerr << "This should be the same as:" << endl;
	cerr << copy << endl;
}

void test4()
{
	cerr << "TEST 4 ---------------------------------" << endl;
	WordTree empty;

	WordTree empty2 = empty;

	cerr << empty << endl;
	cerr << empty2 << endl;
	cerr << "^^^ There should be 2 empty lines here because we created 2 empty trees" << endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	cerr << endl << "ALL TESTS PASSED!" << endl;
}