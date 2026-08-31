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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = 0;
        int curr = 1;
        int last = 0;
        int minAns = INT_MAX;
        int maxAns = INT_MIN;
        ListNode* currNode = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = head->next;
        while(nextNode != NULL)
        {
            if(prevNode != NULL)
            {
                int prevVal = prevNode->val;
                int currVal = currNode->val;
                int nextVal = nextNode->val;
                if(currVal > prevVal && currVal > nextVal)
                {
                    if(first == 0)
                    {
                        first = curr;
                    }
                    if(last != 0)
                    {
                        minAns = min(minAns, curr - last);
                    }
                    last = curr;
                }
                if(currVal < prevVal && currVal < nextVal)
                {
                    if(first == 0)
                    {
                        first = curr;
                    }
                    if(last != 0)
                    {
                        minAns = min(minAns, curr - last);
                    }
                    last = curr;
                }
            }
            curr++;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        maxAns = last - first;
        if(first == 0 || last == 0) return {-1, -1};
        if(minAns == INT_MAX || maxAns == INT_MIN) return {-1, -1};
        return {minAns, maxAns};
    }
};