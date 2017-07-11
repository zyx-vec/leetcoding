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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
		
		ListNode *l, *r;
		l = head, r = head->next;
		
		int tmp;
		while(l && r) {
			tmp = l->val;
			l->val = r->val;
			r->val = tmp;
			
			l = r->next;
		
			r = l ? l->next : NULL;
		}
		
		return head;
    }
};