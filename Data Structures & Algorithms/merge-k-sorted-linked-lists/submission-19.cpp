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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* ans = head;   
        
        priority_queue<
        pair<int, ListNode*>, 
        vector<pair<int, ListNode*>>, 
        greater<pair<int, ListNode*>>> pq;

        for(auto node : lists) {
            pq.push({node->val, node});
        }

        while(!pq.empty()) {
            ListNode* top_node = pq.top().second;
            pq.pop();

            head->next = top_node;
            head = head->next;

            if(top_node->next) {
                pq.push({top_node->next->val, top_node->next});
            }
        }

        return ans->next;
    }
};
