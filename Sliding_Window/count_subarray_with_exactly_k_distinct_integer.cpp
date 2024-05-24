#include <bits/stdc++.h>
using namespace std;

    int subarrayWithAtmostK(vector<int>& nums,int k){
            int n = nums.size();
    int left = 0;
    int right = 0;
    int count = 0;
    unordered_map<int, int> umap;

    for (right = 0; right < n; right++)
    {
        umap[nums[right]]++;

        while (left <= right && umap.size() > k)
        {
            umap[nums[left]]--;
            if (umap[nums[left]] == 0)
                umap.erase(nums[left]);

            left++;
        }
        count+=right-left+1;
    }
    return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarrayWithAtmostK(nums,k) - subarrayWithAtmostK(nums,k-1);
    }
int main(){
  
  vector<int> vec={1,2,1,2,3};
  int k=2;
  cout<<subarraysWithKDistinct(vec,k);
  
return 0;
}