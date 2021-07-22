/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> cachedNodes;

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cHead = new Node(head->val);
        Node* pre = cHead;
        cachedNodes[head] = cHead;
        while (head->next) {
            if (cachedNodes.count(head->next)) {
                pre->next = cachedNodes[head->next];
            } else {
                Node* cur = new Node(head->next->val);
                pre->next = cur;
                cachedNodes[head->next] = cur;
            }
            if (head->random == nullptr) {
                pre->random = nullptr;
            } else if (cachedNodes.count(head->random)) {
                pre->random = cachedNodes[head->random];
            } else {
                Node* cur = new Node(head->random->val);
                pre->random = cur;
                cachedNodes[head->random] = cur;
            }
            pre = pre->next;
            head = head->next;
        }
        if (head->random != nullptr) pre->random = cachedNodes[head->random];
        return cHead;
    }
};
