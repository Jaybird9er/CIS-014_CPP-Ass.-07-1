#include <iostream>
#include <vector>
using namespace std;

/**
*  FUNCTION SIGNATURE:
 * int getMaxProfit(vector<int> &prices)
 * PURPOSE:
 * recommends the maximum profit for an investor by placing one buy and sell (1 of each) order in the time span
 * PARAMETER:
 *  vector<int> &prices
 * RETURN VALUE:
 *  returns the profit after buying and selling
*/
int getMaxProfit(vector<int> &prices)
{
    // cycle through vector to determine if current price is less than future price(s)
    // repeat until loop finds a price to buy
    // if none, return 0
    int buy = 0;
    int sell = 0;
    for(int i = 0; i < prices.size(); i++)
    {
        for(int j = 0; j < prices.size(); j++)
        {
            if (buy == 0)
            {
                if(prices[i] < prices[j])
                {
                    buy = prices[i];
                    i++;
                }
            }
            else
            {
                if(buy > prices[j])
                {
                    buy = prices[j];
                    i++;
                }
            }
        }
    }
    // repeat the loop to find a sell price
    for(int i = 0; i < prices.size(); i++)
    {
        for(int j = 0; j < prices.size(); j++)
        {
            if (sell == 0)
            {
                if(prices[i] > prices[j])
                {
                    sell = prices[i];
                    i++;
                }
            }
            else
            {
                if(sell < prices[j])
                {
                    sell = prices[j];
                    i++;
                }
            }
        }
    }
    // find buy and sell index positions, then subtract (2nd index - 1st index)
    // return difference of (sell - buy) if (2nd index - 1st index) is greater than 0, else return 0
    int buyIndex = 0;
    int sellIndex = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if(prices[i] == buy)
            buyIndex = i;
        else if(prices[i] == sell)
            sellIndex = i;
    }
    if(sellIndex - buyIndex > 0)
        return sell - buy;
    else
        return 0;
}
int main()
    {
    // EXAMPLE USE CASE
    vector<int> arr{1, 2, 4};
    cout << getMaxProfit(arr) << endl; // 3
    vector<int> arr1{4,2,1};
    cout << getMaxProfit(arr1) << endl;
    vector<int> arr2{1};
    cout << getMaxProfit(arr2) << endl;
    vector<int> arr3{1,2,5,1,6};
    cout << getMaxProfit(arr3) << endl;
    vector<int> arr4{3,1,5,2,4};
    cout << getMaxProfit(arr4) << endl;
    return 0;
}
