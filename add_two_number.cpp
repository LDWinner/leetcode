class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result,*tmp;
        int inc = 0;
        result = tmp = nullptr;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(result == nullptr)
            {
                tmp = result = new ListNode((l1->val + l2->val) % 10);
            }
            else
            {
                tmp->next = new ListNode((l1->val + l2->val + inc) % 10);
                tmp = tmp->next;
            }
            inc = (l1->val + l2->val + inc) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *remain = nullptr;
        if(l1 == nullptr && l2 == nullptr && inc)
        {
            tmp->next = new ListNode(inc);
        }
        else if(l1 != nullptr)
        {
            remain = l1;
        }
        else if(l2 != nullptr)
        {
            remain = l2;
        }
         while(remain != nullptr)
            {
                tmp->next = new ListNode((remain->val + inc) % 10);
                tmp = tmp->next;
                inc = (remain->val + inc) / 10;
                remain = remain->next;
            }
            if(inc)
            {
                tmp->next = new ListNode(inc);
            }

        return result;
    }
};
