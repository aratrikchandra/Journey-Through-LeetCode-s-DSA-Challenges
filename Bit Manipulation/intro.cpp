#include <bits/stdc++.h>
using namespace std;

// coverting decimal to binary
string convert_Decimal_to_Binary(int n)
{
    string ans = "";
    while (n > 0)
    {
        if (n % 2)
            ans = '1' + ans;
        else
            ans = '0' + ans;
        n = n / 2;
    }
    return ans;
}
// https://www.geeksforgeeks.org/problems/decimal-to-binary-1587115620/1

// converting binary to decimal
int convert_Binary_to_Decimal(string s)
{
    int n = s.size();
    int val = 0;
    int power_of_2 = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            val = val + power_of_2; // (s[i]*power_of_2)=power_of_2
        }
        power_of_2 = power_of_2 * 2;
    }
    return val;
}
// https://www.geeksforgeeks.org/problems/binary-number-to-decimal-number3525/1

// finding 1's complement

// finding 2's complement

// bit manipulation regarding ith bit
vector<int> bitManipulation_ith_bit(int n, int i)
{
    vector<int> ans;
    // Get the bit value at the "i"th position of "num".
    if ((n & (1 << i - 1)) == 0)
        ans.push_back(0);
    else
        ans.push_back(1);
    // Set the bit at the "i"th position of "num"
    ans.push_back(n | (1 << i - 1));
    // Clear the bit at the "i"th position of "num".
    ans.push_back(n & ~(1 << i - 1));
    return ans;
}
// https://www.codingninjas.com/studio/problems/bit-manipulation_8142533?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// swap two numbers
void swapNumber(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
// https://www.codingninjas.com/studio/problems/swap-two-numbers_1380853?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// find number of set bits in a number
int countSetBytes(int n)
{
    int count = 0;

    while (n > 0)
    {
        if (n & 1) // if n is odd
            count++;

        n = n >> 1; // divide by two
    }
    return count;
}

// find if a number is power of two or not
bool isPowerOfTwo(int num) {
        long n=num;
        if(n==0)
        return false;
        return (n&(n-1))==0?true:false;
    }

// https://leetcode.com/problems/power-of-two/
int main()
{

    return 0;
}