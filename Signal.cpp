/*
* Signal Class that opens a data file containing 17 values per point-in-time sample
* in each row. The data values are normalized per row and concatenated to produce
* the output signal needed for DTW. 
*/

#include "Signal.h"
#include <sstream>
#include <fstream>
#include <iostream>

/*
* Default constructor that opens a data file containing all the of the signals to be processed.
*/
Signal::Signal(string filename)
{
	vector<double> acc_x;
	vector<double> acc_y;
	vector<double> acc_z;
	vector<double> gyr_x;
	vector<double> gyr_y;
	vector<double> gyr_z;
	vector<double> roll;
	vector<double> pitch;
	vector<double> yaw;
	vector<double> emg_1;
	vector<double> emg_2;
	vector<double> emg_3;
	vector<double> emg_4;
	vector<double> emg_5;
	vector<double> emg_6;
	vector<double> emg_7;
	vector<double> emg_8;



	double acc_xVal;
	double acc_yVal;
	double acc_zVal;
	double gyr_xVal;
	double gyr_yVal;
	double gyr_zVal;
	double rollVal;
	double pitchVal;
	double yawVal;
	double emg_1Val;
	double emg_2Val;
	double emg_3Val;
	double emg_4Val;
	double emg_5Val;
	double emg_6Val;
	double emg_7Val;
	double emg_8Val;


 	string line;
	fstream inFile;
	inFile.open(filename.c_str());

	// Open the file containing the data and parse the 17 different values into their 
	// own vector to be stored.
	if (inFile.is_open())
	{
 		while ( getline (inFile,line) )
    	{
    		string value;
      		stringstream lineStream(line);
      		lineStream >>  acc_xVal >> acc_yVal >> acc_zVal 
      		>> gyr_xVal >> gyr_yVal >> gyr_zVal 
      		>> rollVal >> pitchVal >> yawVal 
      		>> emg_1Val >> emg_2Val >> emg_3Val >> emg_4Val >> emg_5Val >> emg_6Val >> emg_7Val >> emg_8Val;

			acc_x.push_back(acc_xVal);
			acc_y.push_back(acc_yVal);
			acc_z.push_back(acc_zVal);

			gyr_x.push_back(gyr_xVal);
			gyr_y.push_back(gyr_yVal);
			gyr_z.push_back(gyr_zVal);

			roll.push_back(rollVal);
			pitch.push_back(pitchVal);
			yaw.push_back(yawVal);

			emg_1.push_back(emg_1Val);
			emg_2.push_back(emg_2Val);
			emg_3.push_back(emg_3Val);
			emg_4.push_back(emg_4Val);
			emg_5.push_back(emg_5Val);
			emg_6.push_back(emg_6Val);
			emg_7.push_back(emg_7Val);
			emg_8.push_back(emg_8Val);

			numOfRows++;
    	}
    
    	inFile.close();
	}

	vectors.push_back(acc_x);
	vectors.push_back(acc_y);
	vectors.push_back(acc_z);
	vectors.push_back(gyr_x);
	vectors.push_back(gyr_y);
	vectors.push_back(gyr_z);
	vectors.push_back(roll);
	vectors.push_back(pitch);
	vectors.push_back(yaw);
	vectors.push_back(emg_1);
	vectors.push_back(emg_2);
	vectors.push_back(emg_3);
	vectors.push_back(emg_4);
	vectors.push_back(emg_5);
	vectors.push_back(emg_6);
	vectors.push_back(emg_7);
	vectors.push_back(emg_8);	

	// Normalizes the vectors
	for(int i = 0; i < 17; i ++)
	{
		double minValue = getMinValue(vectors[i]);
		double maxValue = getMaxValue(vectors[i]);
		vectors[i] = normalizeVector(minValue, maxValue, vectors.at(i));
	}

}

/*
* Destructor that deletes the signal
*/
Signal::~Signal(){

}

/*
* Method that retrieves the entire signal by concatenating the vectors
*/
vector<double> 	Signal::getSignal()
{
	vector<double> concatVector;
	for(int i = 0; i < 17; i ++)
	{
		for(int j = 0; j < numOfRows; j ++)
		{
			concatVector.push_back(vectors.at(i).at(j));
		}
	}

	return concatVector;
}

/*
* Method that normalizes the data values in the row and returns the normalized vector
* To normalize: (x - min)/range
*/
vector<double> Signal::normalizeVector(double min, double max, vector<double> v)
{
	vector<double> normVector;
	int range = max - min;

	for (int i = 0; i < numOfRows; i++)
	{
		normVector.push_back((v[i] - min)/range);
	}

	return normVector;
	
}


/*
* Method that returns the maximum value in the row to be used for normalization
*/
double Signal::getMaxValue(vector<double> v)
{
	double max = 0;

	for(int i = 0; i < numOfRows; i ++)
	{
		if(v[i] > max)
		{
			max = v[i];
		}
	}

	return max;
}

/*
* Method that returns the minumum value in the row to be used for normalization
*/
double Signal::getMinValue(vector<double> v)
{
	double min = 0;

	for(int i = 0; i < numOfRows; i ++)
	{
		if(v[i] < min)
		{
			min = v[i];
		}
	}

	return min;
}
