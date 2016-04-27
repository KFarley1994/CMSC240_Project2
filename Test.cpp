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

	vector<vector<double>> DTW  = DTW::DTWDistance(testVector, testVector2);
	cout << testVector.size() << endl;
	cout << testVector2.size() << endl;
	cout << DTW[ testVector.size() -1 ][ testVector2.size()-1 ] << endl;
	
	for(int i = 0; i < testVector.size(); i ++)
	{
			for (int j =0; j < testVector2.size(); j++)
			{
				cout << "DTW[" << i << "]" << "[" << j << "]" << DTW[i][j] << endl;
			}
	}

}