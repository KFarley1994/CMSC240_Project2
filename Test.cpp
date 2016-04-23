#include "Signal.h"
#include <iostream>

int main(int argc, char *argv[])
{
	Signal testSignal(argv[1]);
	vector<double> testVector = testSignal.getSignal();
	for (int i =0; i <testVector.size(); i++)
	{
		cout << testVector[i] << endl;
	}

}