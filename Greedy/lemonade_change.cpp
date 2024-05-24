#include <bits/stdc++.h>
using namespace std;
 bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int five=0,ten=0;

        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            five++;
            else if(bills[i]==10)
            {
                ten++;
                // we have to give $5 change now
                if(five>0)
                five--;
                else
                return false;
            }
            else{ // $20 bill
            // we have to give $15 change now
            // case 1
            if(five>0 && ten>0)
            {
                five--;
                ten--;
            }
            // case 2
            else if(five>2){
                five-=3;
            }
            else{
                return false;
            }
            }
        }
        return true;
    }
int main(){
  
  vector<int> bills={5,5,5,10,20};
  cout<<lemonadeChange(bills);
return 0;
}

// https://leetcode.com/problems/lemonade-change/submissions/1197411901/