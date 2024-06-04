/*
Title:
Leetcode LCR 024. Reverse Linked List

Description:
Given the head node of a single linked list, invert the list and return the head node of the inverted list.

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
    ListNode* reverseList(ListNode* head) {
        // Method -> Recursion
        return recur(head,nullptr);

    }
private:
    ListNode* recur(ListNode* cur, ListNode* pre){
        if (cur == nullptr) return pre;        // 终止条件
        ListNode* res = recur(cur->next, cur); // 递归后继节点
        cur->next = pre;                       // 修改节点引用指向
        return res;                            // 返回反转链表的头节点
    }
};