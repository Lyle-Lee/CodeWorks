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
        ListNode *dummy_node = new ListNode(-101, head);
        ListNode *pre = dummy_node;
        ListNode *cur = head;
        ListNode *pos = cur;
        while (pos && pos->next) {
            pos = pos->next;
            if (cur->val == pos->val) {
                while (pos && cur->val == pos->val) {
                    pos = pos->next;
                }
                if (cur == head) head = pos;
                pre->next = pos;
                cur = pos;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return head;
    }
};
