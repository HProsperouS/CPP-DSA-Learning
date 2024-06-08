/*
Title:
530. Minimum Absolute Difference in BST

Description:
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the 
values of any two different nodes in the tree.

Example 1:
	Input: root = [4,2,6,1,3]
	Output: 1

Example 2:
    Input: root = [1,0,48,null,null,12,49]
	Output: 1
	
Constraints:
	The number of nodes in the tree is in the range [2, 104].
	0 <= Node.val <= 105
*/
class Solution {
private:
    int ret;
    int pre;
    void inOrder(TreeNode* node){
        if(node == NULL){
            return;
        }
        inOrder(node->left);
        ret = min(ret, node->val - pre);
        pre = node->val;
        inOrder(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        ret = 10000000000;
        pre = -1000000000;
        inOrder(root);
        return ret;
    }
};