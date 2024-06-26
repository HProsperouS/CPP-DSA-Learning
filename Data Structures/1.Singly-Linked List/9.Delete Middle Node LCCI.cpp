/*
Title:
面试题 02.03. Delete Middle Node LCCI
	
Description:
Implement an algorithm to delete a node in the middle 
(i.e., any node but the first and last node, not necessarily the exact middle) of a 
singly linked list, given only access to that node.

Example:
	Input: the node c from the linked list a->b->c->d->e->f
	Output: nothing is returned, but the new linked list looks like a->b->d->e->f
	
*/
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
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
    }
};










