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
    bool hasCycle(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != nullptr) {
            if(ptr->val == 0) {
                return true;
            }

            ptr->val = 0;
            ptr = ptr->next;
        }

        return false;
    }
};
