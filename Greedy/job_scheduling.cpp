#include <bits/stdc++.h>

using namespace std;
// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
static bool comp(Job j1, Job j2){
        return j1.profit>j2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int jobs=0;
        int profit=0;
        
        sort(arr,arr+n,comp);
        int maxDeadline=0;
        for(int i=0;i<n;i++){
            maxDeadline=max(maxDeadline,arr[i].dead);
        }
        vector<int> deadline(maxDeadline+1,-1);
        
        for(int i=0;i<n;i++){
            int j=arr[i].dead;
            while(j>=1 && deadline[j]!=-1)
            j--;
            
            if(j>=1){
                deadline[j]=arr[i].id;
                profit+=arr[i].profit;
                jobs++;
            }
        }
     return {jobs,profit};   
    } 


// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1