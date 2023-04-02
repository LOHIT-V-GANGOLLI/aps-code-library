/*
C++ program to cyclically rotate an array by one.

Example 1:
    Input : array[] = {1, 2, 3, 4, 5}
    Output : array[] = {5, 1, 2, 3, 4}

Example 2:
    Input : array[] = {9, 8, 7, 6, 4, 2, 1, 3}
    Output : array[] = {8, 7, 6, 4, 2, 1, 3, 9}
*/

#include <iostream>
using namespace std;

void rotateArray(int *array, int size);
void printArray(int *array, int size);

//Main function
int main()
{
    //Read the size of the array from the user
    int size = 0;
    cout << "Enter the size of array:";
    cin >> size;

    //Declare an array of given size
    int *array = new int[size];

    //Initialize the array elements 
    cout << "Enter array elements\n";
    for (int index = 0; index < size; index++)
    {
        cout << "Element " << index + 1 << ": ";
        cin >> array[index];
    }

    //Print the array before reverse
    cout << "Before rotation:" << endl;
    printArray(array, size);
    
    //Call the rotateArray function
    rotateArray(array, size);

    //Print the array after rotation
    cout << endl << "After rotation:" << endl;
    printArray(array, size);
    return 0;
}

//Function to cyclically rotate an array by one
void rotateArray(int *array, int size)
{
    //Store the last element of array in temp
    int temp = array[size - 1];

    //Shift right the array elements by one
    for (int i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    
    //Store the temp's value at the beginning  
    array[0] = temp;

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