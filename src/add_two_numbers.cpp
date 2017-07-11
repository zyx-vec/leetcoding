/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOut = 0;
        
        return impl(l1, l2, carryOut);
    }
    
    ListNode* impl(ListNode* l1, ListNode* l2, int carryOut) {
        ListNode *ret, *curr;
        ret = curr = new ListNode(-1);
        while(l1 || l2) {
            int val;
            if(l1 == NULL) {
                while(l2) {
                    val = l2->val + carryOut;
                    carryOut = 0;
                    if(val > 9) { val -=10; carryOut = 1; }
                    curr->next = new ListNode(val);
                    curr = curr->next;
                    l2 = l2->next;
                }
                break;
            } else if(l2 == NULL) {
                while(l1) {
                    val = l1->val + carryOut;
                    carryOut = 0;
                    if(val > 9) { val -= 10; carryOut = 1; }
                    curr->next = new ListNode(val);
                    curr = curr->next;
                    l1 = l1->next;
                }
                break;
            } else {
                val = l1->val + l2->val + carryOut;
                carryOut = 0;
                if(val > 9) { val -= 10; carryOut = 1; }
                curr->next = new ListNode(val);
                curr = curr->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(carryOut) {
            curr->next = new ListNode(1);
        }
        curr = ret->next;
        delete ret;
        return curr;
    }
};