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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *pre = dummyNode;
        ListNode *cur = head;
        while (cur != nullptr) {
            if (cur->val == val) pre->next = cur->next;
            else pre = cur;
            cur = cur->next;
        }
        return dummyNode->next;
    }
};
