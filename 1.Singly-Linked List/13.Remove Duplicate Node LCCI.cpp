/*
Title:
面试题 02.01. Remove Duplicate Node LCCI
Description:
Write code to remove duplicates from an unsorted linked list.


Example 1:
	Input: [1, 2, 3, 3, 2, 1]
	Output: [1, 2, 3]

Example 2:
    Input: [1, 1, 1, 1, 2]
	Output: [1, 2]
	
Constraints:
	The length of the list is within the range[0, 20000].
	The values of the list elements are within the range [0, 20000].
*/

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head){
            return head;
        }
        
        unordered_set<int> occurred = {head->val};
        ListNode* pos = head;
        
        // 枚举前驱节点
        while (pos->next != nullptr) {
            // 当前待删除节点
            ListNode* cur = pos->next;
            if (!occurred.count(cur->val)) {
                occurred.insert(cur->val);
                pos = pos->next;
            }else {
                pos->next = pos->next->next;
            }
        }

        return head;

    }
};









