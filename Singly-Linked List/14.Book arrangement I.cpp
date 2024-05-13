/*
Title:
Leetcode: LCR 123. Book arrangement I

Description:
The bookstore clerk has a list of books in the form of a linked list, 
with each node representing a book and the value in the node representing the book number. 
To make it easier to organize the shelves, the clerk needs to arrange the book list 
upside down, and you can start with the last book and put the books back on the shelf one by one. 
Please return to this list of books in reverse order.

Example 1:
	input：head = [3,6,4,1]
	output：[1,4,6,3]

Constraints:
	0 <= linkedlist.length <= 10000

*/

class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
        //Stack Method
        // Step 1: Stacking: Traverses the linked list and pushes each node value onto the stack.
        // Step 2: Out of stack: pop each node value out of stack, store it in array and return it.
        stack<int> stk;

        while(head != nullptr){
            stk.push(head->val);
            head = head->next;
        }

        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
        
    }
};