struct DLinkedNode {
    int key, val;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head, *tail;
    int size, capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            DLinkedNode *node = cache[key];
            deleteNode(node);
            pushToHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            DLinkedNode *node = cache[key];
            node->val = value;
        } else {
            DLinkedNode *node = new DLinkedNode(key, value);
            if (size < capacity) {
                ++size;
            } else {
                DLinkedNode *lru = tail->prev;
                deleteNode(lru);
                cache.erase(lru->key);
            }
            pushToHead(node);
            cache[key] = node;
        }
    }

    void deleteNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void pushToHead(DLinkedNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
