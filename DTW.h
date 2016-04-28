/*
* This is the header file for the DTW class that computes the 
* minimum distance between two signals or sequences with dynamic
* time warping. 
*/

#ifndef DTW_H
#define DTW_H

#include <vector>
#include "Signal.h"


class DTW
{
	public:
		// 2D vector of doubles to store the two sequences or signals needed to compute the DTW distance.
		static vector< vector<double> > DTWDistance(const vector<double> signalA, const vector<double> signalB);
};

#endif