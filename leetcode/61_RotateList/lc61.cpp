/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1;
        ListNode *cur = head;
        while (cur && cur->next) {
            n++;
            cur = cur->next;
        }
        if (n == 1) return head;
        int new_k = k % n;
        if (new_k == 0) return head;
        ListNode *pre = head;
        while (new_k < n - 1) {
            pre = pre->next;
            new_k++;
        }
        cur->next = head;
        head = pre->next;
        pre->next = nullptr;
        return head;
    }
};
