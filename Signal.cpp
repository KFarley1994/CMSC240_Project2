#include "Signal.h"
#include <sstream>
#include <fstream>
#include <iostream>

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
	ifstream inFile (filename);

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


			/**cout << acc_xVal << endl;
			cout << acc_yVal << endl;
			cout << acc_zVal << endl;

			cout << gyr_xVal << endl;
			cout << gyr_yVal << endl;
			cout << gyr_zVal << endl;

			cout << rollVal << endl;
			cout << pitchVal << endl;
			cout << yawVal << endl;

			cout << emg_1Val << endl;
			cout << emg_2Val << endl;
			cout << emg_3Val << endl;
			cout << emg_4Val << endl;
			cout << emg_5Val << endl;
			cout << emg_6Val << endl;
			cout << emg_7Val << endl;
			cout << emg_8Val << endl;*/

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

	/**vectors[0] = acc_x;
	vectors[1] = acc_y;
	vectors[2] = acc_z;
	vectors[3] = gyr_x;
	vectors[4] = gyr_y;
	vectors[5] = gyr_z;
	vectors[6] = roll;
	vectors[7] = pitch;
	vectors[8] = yaw;
	vectors[9] = emg_1;
	vectors[10] = emg_2;
	vectors[11] = emg_3;
	vectors[12] = emg_4;
	vectors[13] = emg_5;
	vectors[14] = emg_6;
	vectors[15] = emg_7;
	vectors[16] = emg_8;*/

	for(int i = 0; i < 17; i ++)
	{
		double minValue = getMinValue(vectors[i]);
		double maxValue = getMaxValue(vectors[i]);
		vectors[i] = normalizeVector(minValue, maxValue, vectors.at(i));
	}

}

Signal::~Signal(){

}


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
