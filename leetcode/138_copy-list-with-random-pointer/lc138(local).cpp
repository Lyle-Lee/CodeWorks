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
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        } // copy right after self
        for (Node* node = head; node != nullptr; node = node->next->next) {
            node->next->random = node->random != nullptr ? node->random->next : nullptr;
        }
        Node* cHead = head->next;
        Node* cur = cHead;
        while (head) {
            head->next = head->next->next;
            cur->next = cur->next != nullptr ? cur->next->next : nullptr;
            cur = cur->next;
            head = head->next;
        }
        return cHead;
    }
};
