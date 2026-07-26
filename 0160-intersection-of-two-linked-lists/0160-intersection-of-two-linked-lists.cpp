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
    int find(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lA = find(headA);
        int lB = find(headB);

        while(lA > lB)
        {
            lA--;
            headA = headA->next;
        }
        while(lA < lB)
        {
            lB--;
            headB = headB->next;
        }
        while(lA)
        {
            if(headA == headB) return headA;
            lA--;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};