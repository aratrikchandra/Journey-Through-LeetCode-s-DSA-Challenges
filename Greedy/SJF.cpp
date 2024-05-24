#include <bits/stdc++.h>
using namespace std;
// Define the Job class
class Job
{
public:
    int id;
    int arrivalTime;
    int burstTime;

    Job(int _id, int _arrivalTime, int _burstTime)
    {
        id = _id;
        arrivalTime = _arrivalTime;
        burstTime = _burstTime;
    }
};
bool static comp(Job j1, Job j2)
{
    if (j1.arrivalTime == j2.arrivalTime)
    {
        if (j1.burstTime == j2.burstTime)
        {
            return j1.id < j2.id;
        }
        else
            return j1.burstTime < j2.burstTime;
    }
    else
        return j1.arrivalTime < j2.arrivalTime;
}
float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime)
{
    vector<Job> arr;
    for (int i = 0; i < n; i++)
    {
        Job j = Job(i, arrivalTime[i], burstTime[i]);
        arr.push_back(j);
    }

    sort(arr.begin(), arr.end(), comp);
    float totalWaitingTime=0.0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int currentTime = 0;
    int jobsCompleted = 0;
    int i = 0;
    while (jobsCompleted < n)
    {
        while(i<n && arr[i].arrivalTime<=currentTime){
        pq.push({arr[i].burstTime, arr[i].arrivalTime}); // we need min BT, if matches then we need min AT
        i++;
        }

        if(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int BT=it.first;
            int AT=it.second;
            totalWaitingTime+=currentTime-AT;
            currentTime+=BT;
            jobsCompleted++;
        }
        else{
            currentTime=arr[i].arrivalTime; // if the pq is empty when we have to wait till the arrival of the next job
        }

    }
    cout<<"Job Completion Order: ";
    return totalWaitingTime/n;
}
int main()
{

    // Sample input
    vector<int> arrivalTime = {2, 0, 4, 5};
    vector<int> burstTime = {3, 4, 2, 4};
    int n = arrivalTime.size();

    // Call the sjf function
    float avgWaitingTime = sjf(n, arrivalTime, burstTime);

    // Output the result
    cout << "Average Waiting Time: " << avgWaitingTime << endl;

    return 0;
}

// https://www.codingninjas.com/studio/problems/sjf_1172165?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION