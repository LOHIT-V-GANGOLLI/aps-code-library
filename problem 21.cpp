//Finding min and max elements of array using Linear search

#include <iostream>
using namespace std;

void minMax(int *array, int size, int *min, int *max);
void printArray(int *array, int size);

//Main Function
int main()
{
    //Read the size of the array
    int size = 0;
    cout << "Enter the size of array:";
    cin >> size;

    //Create an array with given size
    int *array = new int[size];

    //Initialize the array elements
    cout << "Enter array elements\n";
    for (int index = 0; index < size; index++)
    {
        cout << "Element " << index + 1 << ": ";
        cin >> array[index];
    }

    int min = 0, max = 0 ;
    //Call minMax function
    minMax(array, size, &min, &max);

    //Print the min and max 
    cout << "Minimum = " << min << "\nMaximum = " << max;
    return 0;
}

//Function to find min and max elements in an array
void minMax(int *array, int size, int *min, int *max)
{
    //If there is only one element in array
    if (size == 1)
    {
        *min = array[0];
        *max = array[0];
        return;
    }

    //Initialize min and max with first and second elements
    if (array[0] < array[1])
    {
        *min = array[0];
        *max = array[1];
    }
    else
    {
        *min = array[1];
        *max = array[0];
    }
    

    //Traverse through array and change min, max values
    for (int index = 2; index < size; index++)
    {
        if (array[index] < *min)
        {
            *min = array[index];
        }
        else if (array[index] > *max)
        {
            *max = array[index];
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