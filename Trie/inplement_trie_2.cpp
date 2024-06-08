#include <bits/stdc++.h>
using namespace std;
class Node
{

    // member variables
    Node *links[26];
    int countEndsWith = 0;
    int countPrefix = 0;

public:
    // member functions
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void increaseEnd()
    {
        countEndsWith++;
    }
    void increasePrefix()
    {
        countPrefix++;
    }
    int getEndWith()
    {
        return countEndsWith;
    }
    int getPrefix()
    {
        return countPrefix;
    }
    void decreaseEnd()
    {
        countEndsWith--;
    }
    void decreasePrefix()
    {
        countPrefix--;
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

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEndWith();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // node always exist corresponding to all the characters
            node = node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};

// https://www.naukri.com/code360/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=SUBMISSION