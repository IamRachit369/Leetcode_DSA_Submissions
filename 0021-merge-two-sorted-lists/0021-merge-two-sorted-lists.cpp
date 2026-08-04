class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                ListNode* curr = list1;
                list1 = list1->next;
                curr->next = NULL;

                temp->next = curr;
                temp = temp->next;
            }
            else
            {
                ListNode* curr = list2;
                list2 = list2->next;
                curr->next = NULL;

                temp->next = curr;
                temp = temp->next;
            }
        }

        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

        return head->next;
    }
};