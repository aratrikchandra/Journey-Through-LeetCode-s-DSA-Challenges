#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>> st; // <element,index>
    int i=0;
    StockSpanner() {
        
    }
int prevGreater(int price)
{
    int ans=-1;  // if we dont find pge then return -1;
        while (!st.empty() && st.top().first <= price)
            st.pop();

        if (!st.empty())
            ans = st.top().second;
        st.push({price,i});
        i++;
    return ans;
}
    int next(int price) {
        return i-prevGreater(price);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main(){
  
  
  
return 0;
}