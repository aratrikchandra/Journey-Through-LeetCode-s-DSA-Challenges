#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();

    int left = 0;
    int right = 0;
    int maxLen = 0;
    unordered_map<int, int> umap;

    for (right = 0; right < n; right++)
    {
        umap[fruits[right]]++;

        while (left <= right && umap.size() > 2)
        {
            umap[fruits[left]]--;
            if (umap[fruits[left]] == 0)
                umap.erase(fruits[left]);

            left++;
        }

        maxLen=max(maxLen,right-left+1);
    }
    return maxLen;
}
int main()
{

    vector<int> vec = {1, 2, 3, 2, 2};
    cout << totalFruit(vec);

    return 0;
}

// https://leetcode.com/problems/fruit-into-baskets/submissions/1203236582/