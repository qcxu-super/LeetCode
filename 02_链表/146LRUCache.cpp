#include <map>
using namespace std;

/*
146. LRU 缓存
https://leetcode-cn.com/problems/lru-cache/
*/

class LRUCache {
   public:
    struct Node {
        int key;
        int value;
        Node* pre;
        Node* next;
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
        // 保护结点
        head.next = &tail;
        tail.pre = &head;
    }

    int get(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            Node* curr = hashMap[key];
            // cout << "get: key=" << key << ", value=" << hashMap[key]->value << endl;
            deleteNode(curr);
            addNode(curr);
            return curr->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            Node* curr = hashMap[key];
            curr->value = value;
            deleteNode(curr);
            addNode(curr);
        } else {
            if (hashMap.size() >= capacity) {
                deleteNode(tail.pre);
            }
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            addNode(newNode);
        }
        // cout << "put: key=" << key << ", value="<< hashMap[key]->value << endl;
    }

   private:
    int capacity;
    Node head, tail;
    map<int, Node*> hashMap;

    // 在链表头部增加结点node
    void addNode(Node* node) {
        Node* pHead = &head;
        node->next = pHead->next;
        node->pre = pHead;
        pHead->next->pre = node;
        pHead->next = node;
        hashMap[node->key] = node;
    }

    // 删除结点node
    void deleteNode(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        hashMap.erase(node->key);
        // delete node;  // 不能把node的内存释放掉啊。很多是更新结点位置用的。
    }
};