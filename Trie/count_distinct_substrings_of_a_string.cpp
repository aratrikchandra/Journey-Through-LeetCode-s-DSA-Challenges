#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    // member variables

    Node *links[26];   // Array to store links to child nodes, each index represents a letter
    bool flag = false; // marks the end of a word using true

    // member functions
    bool containsKey(char ch) // checks if the character is already present in the node or not
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node) // Insert a new node with a specific key (letter) into the Trie
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) // Get the node with a specific key (letter) from the Trie
    {
        return links[ch - 'a'];
    }
    void setEnd() // Set the current node as the end of a word
    {
        flag = true;
    }

    bool isEnd() // Check if the current node marks the end of a word
    {
        return flag;
    }
};
int countDistinctSubstrings(string &s)
{
    int n=s.size();
    Node *root= new Node();
    int count=0;
    // generating all substrings
    for(int i=0;i<n;i++){
        Node *node=root; // we will start from the root for every new starting point i
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j])){
                count++;
                node->put(s[j], new Node());
            }
            node=node->get(s[j]);
        }
        node->setEnd();
    }
    return count+1; // we also need to consider the empty string
}
// https://www.naukri.com/code360/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=SUBMISSION
int main(){
  
  
  
return 0;
}