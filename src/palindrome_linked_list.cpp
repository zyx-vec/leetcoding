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
    bool isPalindrome(ListNode* head) {
        
        int len = length(head);
        
        if(head == NULL || len == 1) return true;
        
        ListNode *head1, *head2;
        
        reverseFirstHalf(head, len, &head1, &head2);
        
        bool ret = true;
        while(head1) {
            cout << head1->val << ' ' << head2->val << endl;
            if(head1->val != head2->val) {
                ret = false;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return ret;
    }
    
    int length(ListNode* head) {
        ListNode *curr = head;
        int ret = 0;
        while(curr) {
            ++ret;
            curr = curr->next;
        }
        return ret;
    }
    
    void reverseFirstHalf(ListNode* head, int len, ListNode** head1, ListNode** head2) {
        ListNode *curr = head;
        
        ListNode *n1 = curr->next, *n2;
        n2 = n1 ? n1->next : NULL;
        
        int even = len % 2 ? 0 : 1;
        len = len/2 - 1;    // 6 -> 2, 5 -> 2
        while(len > 0) {
            n1->next = curr;
            curr = n1;
            n1 = n2;
            n2 = n2 ? n2->next : NULL;
            --len;
        }
        head->next = NULL;
        
        if(even) {
            *head1 = curr;
            *head2 = n1;
        } else {
            *head1 = curr;
            *head2 = n1->next;
        }
    }
};