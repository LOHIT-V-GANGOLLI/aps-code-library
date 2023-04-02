/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:

    Input: [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
                Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices);
void printArray(int *array, int size);

int main()
{
    int size = 0;

    //Read the size of the vector from the user
    cout << "Enter the size of array:";
    cin >> size;
    
    //Declare a vector
    vector<int> prices;

    //Initialize the array elements
    cout << "Enter array elements\n";
    for (int index = 0; index < size; index++)
    {
        int x;
        cin >> x;
        prices.push_back(x);
    }

    cout << maxProfit(prices);
    return 0;
}

//Function to find the maximum profit
int maxProfit(vector<int>& prices)
{
    int profit = 0;
    int minprice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < minprice)
        {
            minprice = prices[i];
        }
        else if (prices[i] - minprice > profit)
        {
            profit = prices[i] - minprice;
        }
    }
    return profit;
}
