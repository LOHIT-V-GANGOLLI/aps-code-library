//Program to reverse an array
#include <iostream>

using namespace std;

void reverseArray(int *array, int size);
void swap(int *start, int *end);
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
    for (int index = 0; index < size; index++)
    {
        cout << "\nElement " << index + 1 << ": ";
        cin >> array[index];
    }
    //Print the array before reverse
    cout << "Before reverse" << endl;
    printArray(array, size);

    //Call the reverse function
    reverseArray(array, size);

    //Print the array after reverse
    cout << "After reverse" << endl;
    printArray(array, size);
    return 0;
}

//Function to reverse the array elements
void reverseArray(int *array, int size)
{
    //indices of start and end elements of the array
    int start = 0, end = size - 1;

    //Swap the first and last elements until all the elements are swapped
    while (start < end)
    {
        swap(&array[start], &array[end]);
        start++;
        end--;
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
