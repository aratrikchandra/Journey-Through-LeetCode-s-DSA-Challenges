#include <bits/stdc++.h>

using namespace std;
// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution
{
public:
    bool static comp(struct Job j1, struct Job j2)
    { // sort jobs acc to profit in desc order
        return j1.profit>j2.profit;
    }
    // Function to find the maximum profit and the number of jobs done
    pair<int, int> JobScheduling(Job a[], int n)
    {
        int totalProfit = 0;
        int count = 0;
        sort(a, a + n, comp);
        int maxDead = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].dead > maxDead)
                maxDead = a[i].dead;
        }
        int arr[maxDead + 1]; // -1 represents the slot is Empty
        for(int i=0;i<=maxDead;i++)
        arr[i]=-1;
        for (int i = 0; i < n; i++)
        {
            int d = a[i].dead;
            for (int j = d; j > 0; j--)
            {
                if (arr[j]==-1)
                {
                    arr[j] = a[i].id;
                    count++;
                    totalProfit += a[i].profit;
                    break;
                }
            }
        }

        return make_pair(totalProfit, count);
    }
};
int main()
{
    int n = 4;
    Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    Solution ob;
    // function call
    pair<int, int> ans = ob.JobScheduling(arr, n);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1