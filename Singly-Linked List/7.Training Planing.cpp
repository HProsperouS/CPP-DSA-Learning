/*
Title:
	LCR 140. Training Planing
Description:
	Given a linked list with a head node to record a list of core workout numbers, 
	find and return the penultimate cnt workout number.

Example :
	input：head = [2,4,7,8], cnt = 1
	output：8
	
Constraints:
	1 <= head.length <= 100
	0 <= head[i] <= 100
	1 <= cnt <= head.length
	
*/

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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(cnt--){
            fast = fast->next;
        }
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        return slow;

    }
};