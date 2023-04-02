//Program to sort the array of 0s, 1s, 2s in ascending order without using any sorting algo

#include <iostream>
using namespace std;

void sort(int *array, int size);
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

    //Print the array before sort 
    cout << "Before sort" << endl;
    printArray(array, size);

    //Call the sort function
    sort(array, size);

    //Print the array after sort
    cout << "After sort" << endl;
    printArray(array, size);

    return 0;
}


//Function to sort the array
void sort(int *array, int size)
{
    //c0, c1, c2 variables are used to store the count the occurance of 0s, 1s, 2s in the array
    int c0 = 0, c1 = 0, c2 = 0;

    //Loop to traverse the array and increment the count of c0, c1, c2
    for (int i = 0; i < size; i++)
    {
        if (array[i] == 0)
        {
            c0++;
        }
        if (array[i] == 1)
        {
            c1++;
        }
        if (array[i] == 2)
        {
            c2++;
        }
    }

    //Update the array
    int i = 0;

    //Traverse through array and replace the first c0 number of elements with 0
    while (c0 > 0)
    {
        array[i] = 0;
        i++;
        c0--;
    }

    //Traverse through array and replace the next c1 number of elements with 1
    while (c1 > 0)
    {
        array[i] = 1;
        i++;
        c1--;
    }

    //Traverse through array and replace the next c2 number of elements with 2
    while (c2 > 0)
    {
        array[i] = 2;
        i++;
        c2--;
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