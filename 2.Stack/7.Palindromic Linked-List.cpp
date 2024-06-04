/*
Title:
Leetcode LCR 027. Palindromic linked list

Description:
Given the head node of a linked list, determine whether it is a palindromic linked list.

If a linked list is palindromic, then the sequence of linked list nodes looks 
the same from front to back as from back to front.

Example 1:
	Input: head = [1,2,3,3,2,1]
	Output: true

Example 2:
    Input: head = [1,2]
	Output: false
	
Constraints:
	The length range of the list L is [1, 10^5]
	0 <= node.val <= 9
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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        bool res = true;
        ListNode* curr = head;

        while(head != nullptr){
            stk.push(head->val);
            head = head->next;
        }

        while(curr != nullptr){
            int top = stk.top();
            stk.pop();
            
            int nodeVal = curr->val;
            if(top != nodeVal){
                res = false;
                break;
            }
            curr = curr->next;
        }
        return res;
        
    }
};