class Solution {
public:
    ListNode* listReverse(ListNode* head)
    {
        if(head == NULL) return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverse(ListNode* head, int k)
    {
        if(head == NULL) return NULL;

        ListNode* temp = head;

        for(int i = 0; i < k; i++)
        {
            if(temp == NULL)
            {
                return head;
            }

            temp = temp->next;
        }

        ListNode* nextNode = temp;

        temp = head;

        for(int i = 1; i < k; i++)
        {
            temp = temp->next;
        }

        temp->next = NULL;

        ListNode* currNode = listReverse(head);

        nextNode = reverse(nextNode, k);

        head->next = nextNode;

        return currNode;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        return reverse(head, k);
    }
};