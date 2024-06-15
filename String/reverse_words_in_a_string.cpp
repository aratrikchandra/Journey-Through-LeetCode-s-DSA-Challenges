#include <bits/stdc++.h>
using namespace std;

// python code
// def reverseWords(self, s: str) -> str:
//     words=s.split()
//     words.reverse()

//     return ' '.join(words)

string reverseWords(string s)
{
    int n = s.size();
    vector<string> listOfWords;
    string word = ""; // will hold the current word
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
            word += s[i];
        else
        {
            if (!word.empty())
                listOfWords.push_back(word);
            word = "";
        }
    }
    // to append the last word of the sentence
    if (!word.empty())
        listOfWords.push_back(word);

    reverse(listOfWords.begin(), listOfWords.end());
    string ans = "";
    for (int i = 0; i < listOfWords.size(); i++)
    {
        ans += listOfWords[i];

        // add with space
        if (i != listOfWords.size() - 1)
            ans += ' ';
    }
    return ans;
}
// https://leetcode.com/problems/reverse-words-in-a-string/submissions/1289266930/
int main()
{

    return 0;
}