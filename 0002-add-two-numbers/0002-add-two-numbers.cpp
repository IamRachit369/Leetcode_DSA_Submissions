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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while(l1 != NULL || l2!= NULL || carry != 0)
        {
            ans->next = new ListNode();
            ans = ans->next;
            int l1_val = (l1 == NULL) ? 0 : l1->val;
            int l2_val = (l2 == NULL) ? 0 : l2->val;
            ans->val = l1_val + l2_val + carry;
            carry = ans->val/10;
            ans->val = ans->val%10;
            l1 = (l1 == NULL) ? NULL : l1->next;
            l2 = (l2 == NULL) ? NULL : l2->next;
        }
        return temp->next;
    }
};