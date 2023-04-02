/*
C++ program to merge the overlapping intervals.
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include <iostream>
#include <algorithm>//max(), sort()
#include <vector>
using namespace std;

vector<vector<int> > mergeIntervals(vector<vector<int> >& intervals);
void printIntervals(vector<vector<int> > input);

//Main function
int main()
{
    //Input the number of intervals
    int size;
    cout << "Enter number of intervals: ";
    cin >> size;

    vector<vector<int> > input(size);

    //Read the start and end values for each interval
    for (int i = 0; i < size; i++)
    {
        input[i] = vector<int> (2);
        cout << "Interval " << i + 1 << ":";
        cin >> input[i][0] >> input[i][1];
    }

    //Print the intervals before merge
    cout << "Before merge:" << endl;
    printIntervals(input);
    
    //Function call
    vector<vector<int> > result = mergeIntervals(input);

    //Print the intervals after merge 
    cout << "After merge:" << endl;
    printIntervals(result);
}

//Function to merge all the overlapping intervals
//Returns a vector containing all the merged intervals along with remaining non-overlapping intervals
vector<vector<int> > mergeIntervals(vector<vector<int> >& intervals) 
{
    vector<vector<int> > result;

    //sort the intervals
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
        //If the result vector is empty, add the current intervals to the result
        if (result.size() == 0)
        {
            result.push_back(intervals.at(i));
        }

        //If the last interval in the result and the current interval overlaps, then change the upper bound of the last interval
        else if (result.back()[1] >= intervals[i][0])
        {
            result.back()[1] = max(intervals[i][1], result.back()[1]);
        }

        //If they are non-overlapping, then add the interval to the result
        else
        {
            result.push_back(intervals.at(i));
        }
    }

    return result;
}

//Function to print the array
void printIntervals(vector<vector<int> > input)
{
    cout << "Intervals are: ";
    for (int i = 0; i < input.size(); i++)
    {
        cout << "[" << input[i][0] << "," << input[i][1] << "]  ";;
    }
    cout << endl;
    return;
}
