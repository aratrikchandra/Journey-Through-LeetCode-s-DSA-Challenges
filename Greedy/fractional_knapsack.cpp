#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    bool static comp(struct Item i, Item j)
    {
        double r1 = (double)i.value / (double)i.weight;
        double r2 = (double)j.value / (double)j.weight;

        if (r1 < r2)
            return false;
        else
            return true;
    }
    // function to return fractionalweights
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        double totalProfit = 0;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr + arr[i].weight <= W) // whole element can be taken
            {
                curr += arr[i].weight;
                totalProfit += arr[i].value;
            }
            else  // whole element cannot be taken
            {
                double frac = (double)(W - curr) / (double)arr[i].weight;
                totalProfit += frac * arr[i].value;
                break;
            }
        }
        return totalProfit;
    }
};
int main()
{
    int n = 3, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1