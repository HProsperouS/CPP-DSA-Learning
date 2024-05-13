/*
Title:
Leetcode 83. Remove Duplicates from Sorted List

Description:
Given the head of a sorted linked list, delete 
all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
	Input: head = [1,1,2]
	Output: [1,2]

Example 2:
    Input: head = [1,1,2,3,3]
	Output: [1,2,3]
	
Constraints:
	The number of nodes in the list is in the range [0, 300].
	-100 <= Node.val <= 100
	The list is guaranteed to be sorted in ascending order.
	
*/
// Solution #1
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* previvous = NULL;
        ListNode* current = head;
        
        while(current != nullptr){
            while(previvous && previvous->val == current->val){
                previvous->next = current->next;
                current = previvous->next;
                if(current == nullptr){
                    break;
                }
            }

            if(!current){
                break;
            }

            previvous = current;
            current = current->next;
        }

        return head;

    }
};

Solution #2:
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* current = head;
        
        while(current->next != nullptr){
           if(current->val == current->next->val){
                current->next = current->next->next;
           }else{
                current = current->next;
           }
        }

        return head;

    }
};