/*
C++ program to find the duplicate element in an array.
Given an array of size n + 1, which contains n distinct elements and 1 element is repeated.
The task is to find out the repeated element.

Example 1:
    Input : array[] = {2, 1, 3, 6, 1}
    Output : 1

Example 2:
    Input : array[] = {9, 5, 8, 3, 5, 1, 2}
    Output : 5
*/

#include <iostream>
#include <algorithm>
using namespace std;

int getDuplicate(int *array, int size);
int getDuplicate2(int *array, int size);
void printArray(int *array, int size);

//Main function
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
    cout << "Duplicate = " << getDuplicate(array, size) << endl;
    cout << "Duplicate = " << getDuplicate2(array, size) << endl;
}

//Method 1
//Function to find the duplicate number in an array by linear search
//Time complexity is O(n^n)

int getDuplicate(int *array, int size)
{
    //Choose an element and check if it is present in the remaining array
    for (int i = 0; i < size; i++)
    {
        //Pick one element in the array
        int dup = array[i];

        //Check if the element is present in the remaining array
        for (int j = i + 1; j < size; j++)
        {
            //If found, return the number
            if (array[j] == dup)
            {
                return dup;
            }
        }
    }
    //If not found, return -1
    return -1;
}

//Method 2
//Function to find the duplicate number in an array by sorting
//Time complexity is O(n*logn)

int getDuplicate2(int *array, int size)
{
    //Sort the array and then traverse through it to check if any adjacent elements are equal

    sort(array, array + size);

    for (int i = 0; i < size; i++)
    {
        if (array[i] == array[i+1])
        {
            return array[i];
        }
    }
    //If not found, return -1
    return -1;
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