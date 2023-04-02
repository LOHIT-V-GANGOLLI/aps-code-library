/*C++ program to move all the negative numbers to the beginning of the array.

An array contains both positive and negative numbers in random order.
Rearrange the array elements so that all negative numbers appear before all positive numbers.

Example:
Input : 1, -5, -6, 10, 25, 33, -20
Ouput : -20, -5, -6, 10, 25, 33, 1

Note : Order of elements is not important here.
*/
#include <iostream>
using namespace std;

void moveNegatives(int *array, int size);
void swap(int *start, int *end);
void printArray(int *array, int size);

//Main function
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

    //Print the array before sort
    cout << "Before sort" << endl;
    printArray(array, size);

    //Function call
    moveNegatives(array, size);

    //Print the array before sort
    cout << "After sort" << endl;
    printArray(array, size);
    return 0;
}

//Function to move all the negative numbers to the left side 
void moveNegatives(int *array, int size)
{ 
    //Pointers to both ends of the array
    int start = 0;
    int end = size - 1;

    //Loop until start and end pointers reach
    while (start < end)
    {
        //Increment start pointer if the number is negative
        while (array[start] < 0)
        {
            start++;
        }

        //Decrement end pointer if the number is positive
        while (array[end] >= 0)
        {
            end--;
        }

        //Swap the numbers if start is less than end
        if (start < end)
        {
            swap(&array[start], &array[end]);
            start++;
            end--;
        }
    }
    return;
}

//Function to swap two elements
void swap(int *start, int *end)
{
    int temp = *start;
    *start = *end;
    *end = temp;

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