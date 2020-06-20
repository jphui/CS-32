#include "BballRoster.h"
#include <iostream>
#include <cassert>

using namespace std;

void test()
{
	cerr << "test A" << endl;
	BballRoster s;
	cerr << "test B" << endl;
	s.signPlayer("Higby", "Venus", IntWrapper(10));
	cerr << "test C" << endl;
	s.signPlayer("Vanu", "Excelsior", IntWrapper(20));
	cerr << "test D" << endl;
	BballRoster s2;
	cerr << "test E" << endl;
	s2.signPlayer("Col", "Sigma", IntWrapper(30));
	cerr << "test F" << endl;
	s2 = s;
	cerr << "test G" << endl;
	s2.signPlayer("Eggsy", "Bouillion", IntWrapper(40));
	cerr << "test H" << endl;
}

int main()
{
	test();
	cerr << "DONE" << endl;
}