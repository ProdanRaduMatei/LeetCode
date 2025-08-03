#include <unordered_map>

using namespace std;

class LRUCache
{
private:
    struct Node
    {
        int key, value;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node *> cache;
    int capacity, size;
    Node *head;
    Node *tail;

    void addNode(Node *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void moveToHead(Node *node)
    {
        removeNode(node);
        addNode(node);
    }

    Node *popTail()
    {
        Node *res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        Node *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            cache[key] = node;
            addNode(node);
            ++size;
            if (size > capacity)
            {
                Node *tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
                --size;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */