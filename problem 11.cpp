//Find the min and max elements of array using merge sort

#include <iostream>
using namespace std;

void minMax(int *array, int size, int *min, int *max);
void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int mid, int right);
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
    mergeSort(array, 0, size - 1);
    *min = array[0];
    *max = array[size - 1];
    return;
}

//Function to sort the array
void mergeSort(int *array, int left, int right)
{
    //Find the mid index
    int mid = (left + right) / 2;

    if (left < right)
    {
        //Sort the first half array
        mergeSort(array, left, mid);

        //Sort the second half array
        mergeSort(array, mid + 1, right);

        //Merge the two sorted arrays
        merge(array, left, mid, right);
    }

    return;
}

//Merge two sub arrays
void merge(int *array, int left, int mid, int right)
{
    //Lengths of left and right sub arrays
    int len1 = mid - left + 1;
    int len2 = right - mid;
    
    //Create left and right sub arrays
    int leftArray[len1], rightArray[len2];

    //Copy data from original array to sub arrays
    for (int i = 0; i < len1; i++)
    {
        leftArray[i] = array[i + left];
    }
    for (int i = 0; i < len2; i++)
    {
        rightArray[i] = array[i + mid + 1];
    }

    int i = 0 , j = 0, k = left;
    
    //Over write original array with smallest elements from left and right sub arrays
    while (i < len1 && j < len2)
    {
        if (leftArray[i] < rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    //Copy the remaining elements of left sub array if any 
    while (i < len1)
    {
        array[k] = leftArray[i];
        i++;
        k++;    
    }
    
    //Copy the remaining elements of right sub array if any 
    while (j < len2)
    {
        array[k] = rightArray[j];
        j++;
        k++;    
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