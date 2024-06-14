#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
const int prime = 101;

// Function to calculate the hash
double calculateHash(const string &s) {
    double hash = 0;
    for (int i = 0; i < s.length(); i++) {
        hash += s[i] * pow(prime, i);
    }
    return hash;
}

// Function to update the hash value
double updateHash(double oldHash, char oldChar, char newChar, int n) {
    double newHash = oldHash - oldChar * pow(prime, 0);
    newHash = newHash / prime;
    newHash += newChar * pow(prime, n - 1);
    return newHash;
}

// Function to compare strings
bool compareStrings(const string &text, const string &pattern, int start) {
    for (int i = 0; i < pattern.length(); i++) {
        if (text[start + i] != pattern[i])
            return false;
    }
    return true;
}

// Rabin-Karp algorithm implementation
int RabinKarp(const string &text, const string &pattern) {
    int m = text.length();
    int n = pattern.length();
    
    if (n > m) return -1;  // Edge case: pattern length greater than text length

    double patternHash = calculateHash(pattern);
    string window = text.substr(0, n);
    double textHash = calculateHash(window);

    for (int i = 0; i <= (m - n); i++) {
        if (textHash == patternHash && compareStrings(text, pattern, i)) {
            return i; // If match found
        }

        if (i < m - n) {
            textHash = updateHash(textHash, text[i], text[i + n], n);
        }
    }
    return -1; // If match not found
}

int strStr(const string &haystack, const string &needle) {
    return RabinKarp(haystack, needle);
}
};
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1285948253/
int main(){
  
  
  
return 0;
}