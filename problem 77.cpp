/*
C++ program to find the union and intersection of two sorted arrays.
Given two sorted arrays, the task is to find their union and intersection.

Example 1:

    Input : arr1[] = {1, 3, 4, 5, 7}
            arr2[] = {2, 3, 5, 6} 
    Output : Union : {1, 2, 3, 4, 5, 6, 7} 
             Intersection : {3, 5}
Example 2:

    Input : arr1[] = {2, 5, 6}
            arr2[] = {4, 6, 8, 10} 
    Output : Union : {2, 4, 5, 6, 8, 10} 
             Intersection : {6}
*/

#include <iostream>
using namespace std;

void printUnion(int *array1, int size1, int *array2, int size2);
void printIntersection(int *array1, int size1, int *array2, int size2);
void printArray(int *array, int size);

//Main function
int main()
{
    int size1 = 0, size2 = 0;

    //Read the size of the first array
    cout << "Enter the size of first array:";
    cin >> size1;

    //Create an array with given size
    int *array1 = new int[size1];

    //Initialize the array elements
    cout << "Enter the elements of first array\n";
    for (int index = 0; index < size1; index++)
    {
        cout << "Element " << index + 1 << ": ";
        cin >> array1[index];
    }

    //Read the size of the second array
    cout << "Enter the size of second array:";
    cin >> size2;

    //Create another array with given size
    int *array2 = new int[size2];

    //Initialize the array elements
    cout << "Enter the elements of second array\n";
    for (int index = 0; index < size2; index++)
    {
        cout << "Element " << index + 1 << ": ";
        cin >> array2[index];
    }

    //Print the both arrays
    cout << "Array 1: ";
    printArray(array1, size1);

    cout << "Array 2: ";
    printArray(array2, size2);

    //Function calls
    printUnion(array1, size1, array2, size2);
    
    printIntersection(array1, size1, array2, size2);

    return 0;
}

//Function to print the Union of given arrays
void printUnion(int *array1, int size1, int *array2, int size2)
{
    cout << "Union is: ";
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
        {
            cout << array1[i] << "\t";
            i++;
        }
        else if (array2[j] < array1[i])
        {
            cout << array2[j] << "\t";
            j++;
        }
        else
        {
            cout << array1[i] << "\t";
            i++;
            j++;
        }
    }
    
    while (i < size1)
    {
        cout << array1[i] << "\t";
        i++;
    }
    while (j < size2)
    {
        cout << array2[j] << "\t";
        j++;
    }
    cout << endl;
    return;
}

//Function to print the Intersection of given arrays
void printIntersection(int *array1, int size1, int *array2, int size2)
{
    cout << "Intersection is: ";
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
        {
            i++;
        }
        else if (array2[j] < array1[i])
        {
            j++;
        }
        else
        {
            cout << array1[i] << "\t";
            i++;
            j++;
        }
    }
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