#include "Signal.h"
#include "DTW.h"
#include <iostream>

int main(int argc, char *argv[])
{
	Signal testSignal(argv[1]);
	vector<double> testVector = testSignal.getSignal();
	for (int i =0; i <testVector.size(); i++)
	{
		cout << testVector[i] << endl;
	}

	// vector<double> signalA;
	// vector<double> signalB;
	// int windowSize = ___?;
	// Need to pass in two signals into signalA and signalB with the windowSize to run
	cout << "DTW Distance = " << DTW::DTWDistance(signalA, signalB, windowSize) << endl;;
}