/*
* Header file for the Signal class that includes variable declarations for the 
* storage of the data values from the file, in addition to any methods used in 
* the Signal.cpp file. 
*/

#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>
#include <string>
using namespace std;

class Signal
{
	private:
		vector < vector<double> > vectors; //acc_x acc_y acc_z gyr_x gyr_y gyr_z roll pitch yaw emg_1 emg_2 emg_3 emg_4 emg_5 emg_6 emg_7 emg_8
		vector<double> minValue;
		vector<double> maxValue;
		int numOfRows;
		//void	parseVectors();
		vector<double>    normalizeVector(double min, double max, vector<double> v);
		double getMinValue(vector<double> v);
		double getMaxValue(vector<double> v);

	public:
		Signal(string filename); // Constructor that creates a vector
		~Signal();
		vector<double> 	getSignal(); // Will concatenate rows
		vector < vector<double> > getVectors(){return vectors;};

};

#endif



