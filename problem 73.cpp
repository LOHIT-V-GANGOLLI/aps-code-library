/*
C++ program to find the common elements in 3 sorted arrays.
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: Try to take care of the duplicates without using any additional Data Structure.
Example 1:

    Input:
        size1 = 6; array1 = {1, 5, 10, 20, 40, 80}
        size2 = 5; array2 = {6, 7, 20, 80, 100}
        size3 = 8; array3 = {3, 4, 15, 20, 30, 70, 80, 120}
    
    Output: 20 80

    Explanation: 20 and 80 are the only common elements in array1, array2, array3.

Example 2:
    Input:
        size1 = 3; array1 = {3, 3, 3}
        size2 = 3; array2 = {3, 3, 3}
        size3 = 3; array3 = {3, 3, 3}

    Output: 3
    
    Explanation: 3 is the only common element in array1, array2, array3.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> commonElements(int array1[], int array2[], int array3[], int size1, int size2, int size3);
vector<int> commonElements2(int array1[], int array2[], int array3[], int size1, int size2, int size3);
void getInput(int *array, int size);
void printArray(int *array, int size);
vector<int> _unique (vector<int> r) ;

//Main function
int main()
{
    int size1 = 0, size2 = 0, size3 = 0;

    //Read the size of the first array
    cout << "Enter the sizes of 3 arrays:";
    cin >> size1 >> size2 >> size3;

    //Create 2 arrays with given size
    int *array1 = new int[size1];
    int *array2 = new int[size2];
    int *array3 = new int[size3];

    //Initialize the array1 elements
    cout << "Enter the elements of first array\n";
    getInput(array1, size1);

    //Initialize the array2 elements
    cout << "Enter the elements of second array\n";
    getInput(array2, size2);

    //Initialize the array3 elements
    cout << "Enter the elements of third array\n";
    getInput(array3, size3);

    //Print the arrays
    cout << "Array 1: ";
    printArray(array1, size1);

    cout << "Array 2: ";
    printArray(array2, size2);

    cout << "Array 3: ";
    printArray(array3, size3);

    //Print the resultant vector
    vector<int> result = commonElements2(array1, array2, array3, size1, size2, size3);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }
    return 0;
}

//Function to find the common elements in the given 3 arrays
//Method 1

vector<int> commonElements(int array1[], int array2[], int array3[], int size1, int size2, int size3)
{
    int i = 0, j = 0, k = 0;

    vector<int> result;
    vector<int> temp;

    //Traverse through first, second arrays and find the common elements between them and store them in 'temp' vector
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
            temp.push_back(array1[i]);
            i++;
            j++;
        }
    }

    //Traverse through the third array, temp to find their intersection and store them in 'result' vector
    int x = 0;
    while (k < size3 && x < temp.size())
    {
        if (array3[k] < temp[x])
        {
            k++;
        }
        else if (array3[k] > temp[x])
        {
            x++;
        }
        else
        {
            result.push_back(array3[k]);
            k++;
            x++;
        }
    }

    //Remove the duplicates and return the 'result' vector
    return _unique(result);
}

//Function to find the vector without duplicate elements
vector<int> _unique (vector<int> result) 
{
    vector<int> temp;
    for (int i = 0; i < result.size(); i++)
    {
        if (temp.empty())
        {
           temp.push_back(result[i]);
        }
        if (temp.back() != result[i])
       {
           temp.push_back(result[i]);
        }
    }
    return temp;
}

//Method 2
//Using set and three pointer approach
vector<int> commonElements2(int array1[], int array2[], int array3[], int size1, int size2, int size3)
{
    int i = 0, j = 0, k = 0;
    vector<int> result;
    set<int> temp;
    
    //Iterate through 3 arrays simultaneously using i, j, k
    while (i < size1 && j < size2 && k < size3)
    {
        if (array1[i] == array2[j] == array3[k])
        {
            temp.insert(array1[i]);
            i++;
            j++;
            k++;
        }
        else if (array1[i] <= array2[j] && array1[i] <= array3[k])
        {
            i++;
        }
        else if (array2[j] <= array1[i] && array2[j] <= array3[k])
        {
            j++;
        }
        else if (array3[k] <= array1[i] && array3[k] <= array2[j])
        {
            k++;
        }
    }
    result.assign(temp.begin(), temp.end());
    return result;
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

//Function to print the array
void printArray(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << array[index] << "\t";
    }
    cout << endl;
    return;
}
