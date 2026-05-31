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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        int carry = 0;
        int sum = 0;

        while(p1 != nullptr || p2 != nullptr || carry != 0) { 
            if(p1 != nullptr && p2 != nullptr) {
                sum = p1->val + p2->val + carry;
            } else if(p1 != nullptr) {
                sum = p1->val + carry;
            } else if(p2 != nullptr) {
                sum = p2->val + carry;
            } else {
                sum = carry;
            }

            if(carry == 1) {
                carry = 0;
            }
            
            if(sum > 9) {
                carry = 1;
            }

            sum = sum % 10;
            head->val = sum;

            if(p1 != nullptr) {
                p1 = p1->next;
            }
            
            if(p2 != nullptr) {
                p2 = p2->next;
            }

             if(p1 != nullptr || p2 != nullptr || carry != 0) {
                head->next = new ListNode(0);
                head = head->next;
            }
        }

        return ans;
    }
};
