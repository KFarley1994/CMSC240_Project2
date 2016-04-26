#ifndef DTW_H
#define DTW_H

#include <vector>
#include "Signal.h"


/*
*
*/
class DTW
{
	public:
		double DTWDistance(vector<double> signalA, vector<double> signalB, int windowSize);



};

#endif