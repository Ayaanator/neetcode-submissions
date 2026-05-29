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
        ListNode* fast_ptr = head;

        while(fast_ptr != nullptr && fast_ptr->next != nullptr) {
            ptr = ptr->next;
            fast_ptr = fast_ptr->next->next;

            if(ptr == fast_ptr) {
                return true;
            }
        }

        return false;
    }
};
