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

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i])) // if the character is not present in the node
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }


    bool checkIfAllPrefixExist(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                if (!node->isEnd())
                    return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie *obj = new Trie();
    // building the trie based on all the words in the array
    for (auto &it : a)
    {
        obj->insert(it);
    }

    string longest = "";
    for (auto &it : a)
    {
        if (obj->checkIfAllPrefixExist(it))
        {
            if(it.size()>longest.size() || (it.size()==longest.size() && it<longest)){
                longest=it;
            }
        }
    }

    if(longest.empty())
    return "None";
    else
    return longest;
}
// https://www.naukri.com/code360/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=SUBMISSION
int main()
{
    // Initialize a vector of strings
    vector<string> strings = {"striver", "strive", "striving",
                              "striven", "strived", "striv"};

    // Find the longest complete
    // string in the vector
    string longestComplete = completeString(strings.size(), strings);

    // Print the longest
    // complete string
    cout << "Longest complete string: " << longestComplete << endl;

    return 0;
}
