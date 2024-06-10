/*
Title:
653. Two Sum IV - Input is a BST

Description:
Given the root of a binary search tree and an integer k, return true if there 
exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
	Input: root = [5,3,6,2,4,null,7], k = 9
	Output: true

Example 2:
    Input: root = [5,3,6,2,4,null,7], k = 28
	Output: false
 
Constraints:
	The number of nodes in the tree is in the range [1, 104].
	-104 <= Node.val <= 104
	root is guaranteed to be a valid binary search tree.
	-105 <= k <= 105
*/
class Solution {
private:
    unordered_set<int> hashSet;

public:
    bool findTarget(TreeNode* node, int k) {
        if(node == nullptr){
            return false;
        }

        if(hashSet.count(k - node->val)){
            return true;
        }
        hashSet.insert(node->val);

        return findTarget(node->left, k) || findTarget(node->right, k);
    }
};