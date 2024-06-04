/*
Title:
Leetcode: 19.Remove Nth Node From End of List

Description:
Given the head of a linked list, remove the nth node from the end of the list and return its head.


Example 1:
	Input: head = [1,2,3,4,5], n = 2
	Output: [1,2,3,5]
	
Example 2:
	Input: head = [1], n = 1
	Output: []

Example 3:
	Input: head = [1,2], n = 1
	Output: [1]

Constraints:
	The number of nodes in the list is sz.
	1 <= sz <= 30
	0 <= Node.val <= 100
	1 <= n <= sz
 
	
*/


**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // To add a virtual head node and points its next to the current head;
        ListNode* res = new ListNode(0, head);
        // Make the slow pointer at the new head node, so that when the fast point reach the end, slow pointer is at (nth-1) node
        ListNode* slow = res; 
        ListNode* fast = head;

        while(n--){
            fast = fast->next;
        }

        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = nodeToDelete->next;
        delete nodeToDelete;

        return res->next;
    }
};