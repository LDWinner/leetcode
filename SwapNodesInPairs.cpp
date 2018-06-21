#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* swapPairs(ListNode* head) {
        ListNode* n = head;
        ListNode* prev;
        while(n && n->next)
        {
            ListNode* tmp = n->next;
            if( n == head )
            {
                n->next = tmp->next;
                tmp->next = head;
                head = tmp;
            }
            else
            {
                n->next = tmp->next;
                tmp->next = n;
                prev->next = tmp;
            }
            prev = n;
            n = n->next;
        }
        return head;
    }
};
