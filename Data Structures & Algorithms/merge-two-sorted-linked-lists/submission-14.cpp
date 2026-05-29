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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* n1 = list1;
        ListNode* n2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* start = dummy;

        int num = 0;

        if (n1 == nullptr) return n2;
        if (n2 == nullptr) return n1;

        while(n1 != nullptr && n2 != nullptr) {

            if(n1 != nullptr && n2 != nullptr) {
                if(n1->val > n2->val) {
                    dummy->next = n2;
                    n2 = n2->next;
                } else {
                    dummy->next = n1;
                    n1 = n1->next;
                }

                dummy = dummy->next;
            }
        }

        while(n1 != nullptr) {
                dummy->next = n1;
                dummy = dummy->next;
                n1 = n1->next;
        }

        while(n2 != nullptr) {
                dummy->next = n2;
                dummy = dummy->next;
                n2 = n2->next;
        }

        return start->next;
    }
};
