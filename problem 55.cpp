/*
*************KADANE'S ALGORITHM*************
C++ program to find the contiguous sub-array with maximum sum.

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Example 1:

    Input : N = 5
            arr[] = {1,2,3,-2,5}
    Output: 9
    Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

Example 2:

    Input : N = 4
            arr[] = {-1,-2,-3,-4}
    Output: -1
    Explanation: Max subarray sum is -1 of element (-1)

*/
#include <iostream>
using namespace std;

int maxSubarraySum(int array[], int size);
void printArray(int *array, int size);

int main()
{
    int size = 0;

    //Read the size of the array from the user
    cout << "Enter the size of array:";
    cin >> size;
    
    //Declare an array of given size
    int array[size];

    //Initialize the array elements
    cout << "Enter array elements\n";
    for (int index = 0; index < size; index++)
    {
        cout << "Element " << index + 1 << ": ";
        cin >> array[index];
    }

    //Print the array
    printArray(array, size);

    //Function call
    cout << maxSubarraySum(array, size);
    return 0;
}

//Function to find the max sum of contiguous sub array.
int maxSubarraySum(int array[], int size)
{
    int max_ending_here = 0, max_sum = INT_MIN;

    //iterating over array
    for (int i = 0; i < size; i++)
    {
        max_ending_here += array[i];

        //Seeing if adding current element increases the sum of not
        if (max_ending_here > max_sum)
        {
            max_sum = max_ending_here;  
        }
        //At any index, if the max sum upto here becomes negative, then make it zero
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }  
    }
    return max_sum;
}

//Function to print the array
void printArray(int *array, int size)
{
    cout << "Array elements are: ";
    for (int index = 0; index < size; index++)
    {
        cout << array[index] << "\t";
    }
    cout << endl;
    return;
}