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
		static double DTWDistance(const vector<double> signalA, const vector<double> signalB);// int windowSize);

};

#endif