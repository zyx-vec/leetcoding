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
    ListNode* reverseList(ListNode* head) {
		ListNode* temp1 = NULL;
		ListNode* temp2 = NULL;
		ListNode* temp3 = NULL;
		if(!head || !head->next) return head;
		
		temp1 = head;
		temp2 = temp1->next;
		temp3 = temp2->next;
		while(temp3){
			temp2->next = temp1;    //改变指针指向
			temp1 = temp2;	        //三个指针依次往后移动
			temp2 = temp3;
			temp3 = temp3->next;
		}
		temp2->next = temp1;
		head->next = NULL;
		head = temp2;
		
		return head;
    }
};