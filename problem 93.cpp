/*
Given two sorted arrays array1[], array2[] of size1, size2.
Each array is sorted in non-decreasing order.
Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

Example 1:

    Input:
        size1 = 4, size2 = 5
        array1[] = {1, 3, 5, 7}
        array2[] = {0, 2, 6, 8, 9}
    Output: 0 1 2 3 5 6 7 8 9
    Explanation: Since you can't use any extra space, modify the given arrays to form 
        array1[] = {0, 1, 2, 3}
        array2[] = {5, 6, 7, 8, 9}

Example 2:

    Input:
        size1 = 2, size2 = 3
        array1[] = {10, 12}
        array2[] = {5, 18, 20}
    Output: 5 10 12 18 20
    Explanation: Since you can't use any extra space, modify the given arrays to form 
        array1[] = {5, 10}
        array2[] = {12, 18, 20}
*/

#include <iostream>
#include <algorithm>
using namespace std;

void getInput(int *array, int size);
void mergeTwoArrays(int *array1, int size1, int *array2, int size2);
void swap(int *a, int *b);
void printArray(int *array, int size);

//Main function
int main()
{
    int size1 = 0, size2 = 0;

    //Read the size of the first array
    cout << "Enter the sizes of 2 arrays:";
    cin >> size1 >> size2;

    //Create 2 arrays with given size
    int *array1 = new int[size1];
    int *array2 = new int[size2];

    //Initialize the array1 elements
    cout << "Enter the elements of first array\n";
    getInput(array1, size1);

    //Initialize the array2 elements
    cout << "Enter the elements of second array\n";
    getInput(array2, size2);

    //Print the arrays before merge
    cout << "Before merge:" << endl;
    cout << "Array 1: ";
    printArray(array1, size1);

    cout << "Array 2: ";
    printArray(array2, size2);

    //Function call
    mergeTwoArrays(array1, size1, array2, size2);

    //Print the arrays after merge 
    cout << "After merge:" << endl;
    cout << "Array 1: ";
    printArray(array1, size1);

    cout << "Array 2: ";
    printArray(array2, size2);
}

//Function to read the array elements
void getInput(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >>  array[i];
    }
    return;
}

//Function to merge the two sorted arrays
void mergeTwoArrays(int *array1, int size1, int *array2, int size2)
{
    for (int i = size1 - 1, j = 0; i >= 0 && j < size2; i--, j++)
    {
        if (array1[i] > array2[j])
        {
            swap(&array1[i], &array2[j]);
        }
    }
        
    sort(array1, array1 + size1);
    sort(array2, array2 + size2);
    
    return;
}

//Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
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