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
    void dfs(TreeNode* root, int& pre, int& ans){
        if(root == nullptr){
            return;
        }
        dfs(root->left, pre, ans);
        if(pre == -1){
            pre = root->val;
        }else{
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};