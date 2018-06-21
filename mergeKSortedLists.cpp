#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int> > pq;
        vector<ListNode*>::iterator listNodeIt;
        for(listNodeIt = lists.begin();listNodeIt != lists.end();listNodeIt++)
        {
            ListNode *node = *listNodeIt;
            while(node)
            {
                pq.push(node->val);
                node = node->next;
            }
        }
        if(pq.empty())
            return NULL;
        ListNode *result = new ListNode(pq.top());
        ListNode *n = result;
        pq.pop();
        while(!pq.empty())
        {
            n->next = new ListNode(pq.top());
            n = n->next;
            pq.pop();
        }
        return result;

    }
};

int main()
{
    vector<ListNode*> lists;
    ListNode* head = new ListNode(4);
    ListNode* n = head;
    n->next = new ListNode(3);
    n = n->next;
    n->next = new ListNode(1);
    lists.push_back(head);
    Solution s;
    s.mergeKLists(lists);
}
