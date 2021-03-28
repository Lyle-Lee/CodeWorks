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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = head;
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                pre->next = cur->next;
            }
            cur = cur->next;
            pre = cur;
        }
        return head;
    }
};
