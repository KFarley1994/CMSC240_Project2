#include "Signal.h"
#include "DTW.h"
#include <iostream>

int main(int argc, char *argv[])
{
	Signal testSignal(argv[1]);
	vector<double> testVector = testSignal.getSignal();
	for (int i =0; i <testVector.size(); i++)
	{
		cout << "testVector[" << i << "]" << testVector[i]  << endl;
	}

	cout << endl;

	Signal testSignal2(argv[2]);
	vector<double> testVector2 = testSignal2.getSignal();
	for (int i =0; i <testVector2.size(); i++)
	{
		cout << "testVector2[" << i << "]" << testVector2[i] << endl;
	}

	// vector<double> signalA;
	// vector<double> signalB;
	// int windowSize = ___?;
	// Need to pass in two signals into signalA and signalB with the windowSize to run
	double DTWDistance =  DTW::DTWDistance(testVector, testVector2);
	cout << "DTW Distance = " <<  DTWDistance << endl;
}