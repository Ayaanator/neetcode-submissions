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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        ListNode* ans = head;
        int length = 0;

        while(node != nullptr) {
            node = node->next;
            length++;
        }
        
        int ctr = 0;
        node = head;

        if(length - n == 0) {
            return head->next;
        }

        while(node != nullptr) {
            if(length - n == ctr + 1 && ctr < length - 1) {
                node->next = node->next->next;
            } else {
                node = node->next;
            }

            ctr++;
        }
        
        return ans;
    }
};
