#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// it will have data offf key value and its count of accessing it
struct node
{
public:
    int key, value, ct;
    node *next, *prv;
    node(int _key, int _value)
    {
        key = _key;
        value = _value;
        ct = 1;
    }
};

// it is same implemented as lru
struct List
{
public:
    int size;
    node *head, *tail;
    List()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prv = head;
        size = 0;
    }

    void addfront(node *node_to_be_added)
    {
        node *temp = head->next;
        node_to_be_added->next = temp;
        node_to_be_added->prv = head;
        head->next = node_to_be_added;
        temp->prv = node_to_be_added;
        size++;
    }
    void removenode(node *node_to_be_deleted)
    {
        node *del_prv = node_to_be_deleted->prv;
        node *del_next = node_to_be_deleted->next;
        del_prv->next = del_next;
        del_next->prv = del_prv;
        size--;
    }
};
class LFUCache
{
    map<int, node *> keynode;
    map<int, List *> freqlistmap;
    int maxSizeCache, minFreq, curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        curSize = 0;
        minFreq = 0;
    }

    int get(int key)
    {
        
    }

    void put(int key, int value)
    {
    }
};
int main()
{
    return 0;
}