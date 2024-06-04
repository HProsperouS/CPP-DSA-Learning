/*
Title:
LCR 175. Calculate the depth of a binary tree

Description:
For a company structure recorded as a binary tree, return the number of tiers for the company.

Example 1:
	root = [1, 2, 2, 3, null, null, 5, 4, null, null, 4]
	Output: 4
	Explanation: The maximum depth of the binary tree in the example above is 4, and there are 4 nodes on the longest path to the leaf node along the path 1 -> 2 -> 3 -> 4 or 1 -> 2 -> 5 -> 4.

Constraints:
	The total number of nodes is <= 10000
*/
class Solution {
    int maxDepth;
    void dfs(TreeNode *root, int depth){
        if(depth > maxDepth) maxDepth = depth;
        if(root){
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    }
public:
    int calculateDepth(TreeNode* root) {
        maxDepth = 0;
        dfs(root, 0);
        return maxDepth;
    }
};