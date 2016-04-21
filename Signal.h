#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>
using namespace std;

class Signal
{
	private:
		vector < vector<double> > vectors; //acc_x acc_y acc_z gyr_x gyr_y gyr_z roll pitch yaw emg_1 emg_2 emg_3 emg_4 emg_5 emg_6 emg_7 emg_8
		vector<double> minValue;
		vector<double> maxValue;
		int numOfRows;
		void	parseVectors();
		void    normalizeVector();
		

	public:
		Signal(string filename); // Constructor that creates a vector
		~Signal();
		vector<double> 	getSignal(); // Will concatenate rows

};

#endif



