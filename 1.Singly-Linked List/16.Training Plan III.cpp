/*
Title:
Leetcode LCR 141. Training Plan III

Description:
Given a single linked list with a head node to record a 
series of core muscle training numbers, record the series of training 
numbers in reverse order in the linked list and return.

Example 1:
	input：head = [1,2,3,4,5]
	output：[5,4,3,2,1]

Example 2:
    input：head = [1,2]
	output：[2,1]
	
Example 3:
    input：head = []
	output：[]
	
Constraints:
	The number of nodes in the list ranges from [0, 5000]
	-5000 <= Node.val <= 5000
*/
class Solution {
public:
    ListNode* trainningPlan(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = trainningPlan(head->next);
        head->next->next = head;
        head->next = NULL;
    }
};