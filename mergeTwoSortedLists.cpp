#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *head,*curr;
            head = curr = NULL;
            while(l1 != NULL && l2 != NULL )
            {
                int min;
                if(l1->val <= l2->val)
                {
                    min = l1->val;
                    l1 = l1->next;
                }
                else 
                {
                    min = l2->val;
                    l2 = l2->next;
                }
                if(!head)
                {
                    curr = head = new ListNode(min);
                }
                else
                {
                    curr->next = new ListNode(min);
                    curr = curr->next;
                }
            }
            while(l1 != NULL)
            {
                if(!head)
                {
                    curr = head = new ListNode(l1->val);
                }
                else
                {
                    curr->next = new ListNode(l1->val);
                    curr = curr->next;
                }
                l1 = l1->next;
            }
            while(l2 != NULL)
            {
                if(!head)
                {
                    curr = head = new ListNode(l2->val);
                }
                else
                {
                    curr->next = new ListNode(l2->val);
                    curr = curr->next;
                }
                l2 = l2->next;
            }
            return head;

        }
};
