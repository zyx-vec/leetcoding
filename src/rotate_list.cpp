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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *l, *r;
        l = r = head;
        
        if(l == NULL) return NULL;
        
        int len = listLen(head);
        
        k = k % len;
        if(k == 0) return head;
        
        while(r && k > 0) {
            r = r->next;
            k--;
        }
        cout << r->val << endl;
        
        while(r->next != NULL) {
            l = l->next;
            r = r->next;
        }
        
        ListNode *newHead = l->next;
        l->next = NULL;
        r->next = head;
        
        
        return newHead;
    }
    
    int listLen(ListNode* head) {
        ListNode *p = head;
        int len = 0;
        while(p) {
            len++;
            p = p->next;
        }
        
        return len;
    }
};