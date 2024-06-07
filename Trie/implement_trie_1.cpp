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
    void put(char ch, Node *node)  // Insert a new node with a specific key (letter) into the Trie
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)     // Get the node with a specific key (letter) from the Trie
    {
        return links[ch - 'a'];
    }
    void setEnd() // Set the current node as the end of a word
    {
        flag = true;
    }

    bool isEnd()    // Check if the current node marks the end of a word
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

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i])) // if the character is not present in the node
            {
                return false;
            }

            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i])) // if the character is not present in the node
            {
                return false;
            }

            node = node->get(prefix[i]);
        }
        return true;
    }
};

// https://leetcode.com/problems/implement-trie-prefix-tree/submissions/1279870246/
int main()
{
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");

    cout << "Search if Strawberry exists in trie: " << (trie.search("strawberry") ? "True" : "False") << endl;

    cout << "Search if Strike exists in trie: " << (trie.search("strike") ? "True" : "False") << endl;

    cout << "If words is Trie start with Stri: " << (trie.startsWith("stri") ? "True" : "False") << endl;

    return 0;
}