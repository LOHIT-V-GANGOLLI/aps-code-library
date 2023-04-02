/*
Given an array arr[] denoting heights of N towers and a positive integer K.
You have to modify the height of each tower either by increasing or decreasing them by K only once.
After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Example 1:
    Input: K = 2, N = 4, Arr[] = {1, 5, 8, 10}
    Output: 5
    Explanation: The array can be modified as {3, 3, 6, 8}.
    The difference between the largest and the smallest is 8-3 = 5.

Example 2:
    Input: K = 3, N = 5, Arr[] = {3, 9, 12, 16, 20}
    Output: 11
    Explanation: The array can be modified as {6, 6, 9, 13, 17}.
    The difference between the largest and the smallest is 17-6 = 11.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int *array, int size, int k);
void printArray(int *array, int size);

//Main function
int main()
{
    int size = 0, k = 0;

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

    cout << "Enter k value: ";
    cin >> k;

    //Print the array
    printArray(array, size);

    //Function call
    cout << getMinDiff(array, size, k);
}

//Function to get the minimum difference between the longest and shortest heights
int getMinDiff(int *array, int size, int k)
{
    int *mn, *mx;

    //Modify the height of each tower
    for (int index = 0; index < size; index++)
    {
        if (array[index] - k > 0)
        {
            array[index] -= k;
        }
        else
        {
            array[index] += k;
        }
    }

    //Find the min and max heights
    mx = max_element(array, array + size);
    mn = min_element(array, array + size);

    //Return the difference between max and min heights
    return *mx - *mn;
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
