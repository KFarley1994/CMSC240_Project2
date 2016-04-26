/*
* DTW class
*/

#include "DTW.h"
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

/*
*
*/
double distance(double x, double y)
{
    return sqrt(pow((x-y), 2));
}

/*
*
*/
vector<double> DTW::DTWDistance(vector<double> signalA, vector<double> signalB, int windowSize) 
{
    int m = signalA.size();
    int n = signalB.size();

    // Create the matrix
    double DTW[m][n];
    DTW[0][0] = distance(signalA[0], signalB[0]);
    
    // Not sure whether or not to include this..
    windowSize = max(windowSize, abs(m-n)) // adapt window size (*)
 
    // Calculate the first row
    for (int i = 1; i < m; i++)
    {
        DTW[i][0] = cost[i-1][0] + distance(signalA[i], signalB[0]);
    }   
    // Calculate the first column
    for (int j = 1; j < n; j++)
    {
        cost[0][j] = cost[0][j-1] + distance(signalA[0], signalB[j]);
    }

    // Populate the matrix
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            DTW[i][j] = min(DTW[i-1][j], min(DTW[i][j-1], DTW[i-1][j-1])) + distance(signalA[i], signalB[j]);
        }
    }

    return DTW[m-1, n-1]
}