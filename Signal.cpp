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

	int count = 0;

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

			acc_x[count] = acc_xVal;
			acc_y[count] = acc_yVal;
			acc_z[count] = acc_zVal;

			gyr_x[count] = gyr_xVal
			gyr_y[count] = gyr_yVal;
			gyr_z[count] = gyr_zVal;

			roll[count] = rollVal;
			pitch[count] = pitchVal;
			yaw[count] = yawVal;

			emg_1[count] = emg_1Val;
			emg_2[count] = emg_2Val;
			emg_3[count] = emg_3Val;
			emg_4[count] = emg_4Val;
			emg_5[count] = emg_5Val;
			emg_6[count] = emg_6Val;
			emg_7[count] = emg_7Val;
			emg_8[count] = emg_8Val;

			count++;
    	}
    
    	inFile.close();
	}

	for(int i = 0; i < count; i ++)
	{

	}

}

Signal::~Signal(){

}

vector<double> 	Signal::getSignal()
{
	return vectors;
}

void Signal::getMaxValues()
{

}

void Signal::getMinValues()
{
	
}
