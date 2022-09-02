#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class LRUCache
{
    int lar_cap;

public:
    class node
    {
    public:
        int key, val;
        node *next = NULL;
        node *prv = NULL;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        lar_cap = capacity;
        head->next = tail;
        tail->prv = head;
    }

    void deletenode(node *node_to_be_deleted)
    {
        node *prv_add_of_del = node_to_be_deleted->prv;
        node *next_add_of_del = node_to_be_deleted->next;
        prv_add_of_del->next = next_add_of_del;
        next_add_of_del->prv = prv_add_of_del;
    }
    void addnodeatheadstart(node *node_to_be_added)
    {
        node *next_node_of_added = head->next;
        node_to_be_added->next = next_node_of_added;
        node_to_be_added->prv = head;
        head->next = node_to_be_added;
        next_node_of_added->prv = node_to_be_added;
    }
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *finded_node = m[key];
            int key_find = finded_node->key;
            int val_find = finded_node->val;
            m.erase(key);
            deletenode(finded_node);
            addnodeatheadstart(finded_node);
            m[key] = head->next;
            return val_find;
        }
        return -1;
    }

    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        {
            node *existing_node = m[key];
            m.erase(key);
            deletenode(existing_node);
        }
        else if (m.size() == lar_cap)
        {
            m.erase(tail->prv->key);
            deletenode(tail->prv);
        }
        addnodeatheadstart(new node(key, value));
        m[key] = head->next;
    }
};

int main()
{
    return 0;
}