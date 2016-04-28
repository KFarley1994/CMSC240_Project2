/*
* DTW class
*/

#include "DTW.h"
#include <vector>
#include <utility>
#include <cmath>
#include <iostream>

using namespace std;

/*
*
*/
double distanceFunction(double x, double y)
{
    return sqrt(pow((x-y), 2));
}

/*
*
*/
vector< vector<double> > DTW::DTWDistance(const vector<double> signalA, const vector<double> signalB)// int windowSize) 
{
    const int m = signalA.size();
    const int n = signalB.size();
    // Create the matrix
    vector< vector<double> > DTW(m, vector<double>(n));
    cout << " test" << endl;
    DTW[0][0] = distanceFunction(signalA[0], signalB[0]);
    
    // Not sure whether or not to include this..
    //windowSize = max(windowSize, abs(m-n)) // adapt window size (*)
 
    // Calculate the first row
    for (int i = 1; i < m; i++)
    {
        DTW[i][0] = DTW[i-1][0] + distanceFunction(signalA[i], signalB[0]);
    }   
    // Calculate the first column
    for (int j = 1; j < n; j++)
    {
        DTW[0][j] = DTW[0][j-1] + distanceFunction(signalA[0], signalB[j]);
    }

    // Populate the matrix
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            DTW[i][j] = min(DTW[i-1][j], min(DTW[i][j-1], DTW[i-1][j-1])) + distanceFunction(signalA[i], signalB[j]);
        }
    }

    cout << m-1 << " " << n-1 << " "<< DTW[m-1][n-1] << endl;
    return DTW;
}