#include "Signal.h"
#include <sstream>

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

	if (myfile.is_open())
	{
 		while ( getline (inFile,line) )
    	{

    		string value;
      		stringstream lineStream(line);
      		ss >>  acc_xVal >> acc_yVal >> acc_zVal 
      		>> gyr_xVal >> gyr_yVal >> gyr_zVal 
      		>> rollVal >> pitchVal >> yawVal 
      		>> emg_1Val >> emg_2Val >> emg_3Val >> emg_4Val >> emg_5Val >> emg_6Val >> emg_7Val >> emg_8Val;

			acc_x[numOfRows] = acc_xVal;
			acc_y[numOfRows] = acc_yVal;
			acc_z[numOfRows] = acc_zVal;

			gyr_x[numOfRows] = gyr_xVal
			gyr_y[numOfRows] = gyr_yVal;
			gyr_z[numOfRows] = gyr_zVal;

			roll[numOfRows] = rollVal;
			pitch[numOfRows] = pitchVal;
			yaw[numOfRows] = yawVal;

			emg_1[numOfRows] = emg_1Val;
			emg_2[numOfRows] = emg_2Val;
			emg_3[numOfRows] = emg_3Val;
			emg_4[numOfRows] = emg_4Val;
			emg_5[numOfRows] = emg_5Val;
			emg_6[numOfRows] = emg_6Val;
			emg_7[numOfRows] = emg_7Val;
			emg_8[numOfRows] = emg_8Val;

			numOfRows++;
    	}
    
    	inFile.close();
	}

	vectors[0] = acc_x;
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
	vectors[16] = emg_8;	

	for(int i = 0; i < 17; i ++)
	{
		minValue[i] = getMinValues(vectors[i]);
		maxValue[i] = getMaxValues(vectors[i]);
	}

}

Signal::~Signal(){

}

vector<double> 	Signal::getSignal()
{
	return vectors;
}

vector<double> Signal::normalizeVector()
{
	
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

}
