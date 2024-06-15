#include <bits/stdc++.h>
using namespace std;
int mod=(1e9)+7;

int distinctSubseqII(std::string s) {
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    std::unordered_map<char, int> map;
    
    // base case
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % mod;

        if (map.find(s[i - 1]) != map.end()) {
            // if the character existed previously
            int j = map[s[i - 1]];
            dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
        }

        map[s[i - 1]] = i; // storing (char, index in dp array)
    }
    
    // Subtract 1 to exclude the empty subsequence
    return (dp[n] - 1 + mod) % mod; // if dp[n] is itself the value (1e9)+7 then just returning dp[n]-1 would result in -1
}
// https://leetcode.com/problems/distinct-subsequences-ii/submissions/1288327483/
int main(){
  
  
  
return 0;
}