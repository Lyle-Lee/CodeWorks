/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != curB) {
            curA = curA == nullptr ? headB : curA->next;
            curB = curB == nullptr ? headA : curB->next;
        }
        return curA;
    }
};
