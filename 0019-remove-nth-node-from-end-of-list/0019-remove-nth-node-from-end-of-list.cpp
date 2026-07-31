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
    int findLen(ListNode* head)
    {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = findLen(head);
        int toRemove = (length - n) + 1;
        cout << toRemove << endl;
        if(toRemove == 1)
        {
            return head->next;
        }
        ListNode* prev = NULL;
        ListNode* nextNode = head->next;
        while(temp->next != NULL)
        {
            toRemove--;
            if(toRemove == 0)
            {
                prev->next = nextNode;
                break;
            }
            prev = temp;
            temp = nextNode;
            nextNode = nextNode->next;
        }
        if(toRemove)
        {
            prev->next = nextNode;
        }
        return head;
    }
};