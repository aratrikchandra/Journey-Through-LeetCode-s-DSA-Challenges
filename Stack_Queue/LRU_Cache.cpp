#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {

public:
    Node *head, *tail;
    int capacity;
    unordered_map<int, Node*> map;
    LRUCache(int capacity) {
        this->capacity = capacity;
        // initializing head and tail for every new LRU Cache
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(int key, int val) {
        // always insert the new node just next to the head node
        Node* newNode = new Node(key, val);
        Node* temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    void deleteNode(Node* node) {
        Node* left = node->prev;
        Node* right = node->next;

        right->prev = left;
        left->next = right;
        delete node;
    }
    int get(int key) {
        // check if the key exists
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            int res = node->value;
            // remove the node
            deleteNode(node);
            map.erase(key);
            // insert the node right after head
            addNode(key, res);
            map[key] = head->next;
            return res;
        }

        return -1; // if the key does not exist
    }

// If we check for overflow first then the potential issue is:

// In your put method, when the cache is full, you’re deleting the least recently used node and removing its key from the map. However, you’re doing this before checking if the key already exists in the map. This could lead to a situation where you’re deleting a node that you’re about to update.


    void put(int key, int value) {
        // if the key already exists
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            // remove the node
            deleteNode(node);
            map.erase(key);
        }
        // check if overflow
        if (map.size() == capacity) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(key, value);
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// https://leetcode.com/problems/lru-cache/submissions/1283088984/
int main()
{

    return 0;
}