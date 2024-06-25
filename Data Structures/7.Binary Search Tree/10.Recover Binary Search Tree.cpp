/*
Title:
99. Recover Binary Search Tree

Description:
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

Example 1:
	Input: root = [1,3,null,null,2]
	Output: [3,1,null,null,2]
	Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
    Input: root = [3,1,4,null,null,2]
	Output: [2,1,4,null,null,3]
	Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
	
Constraints:
	The number of nodes in the tree is in the range [2, 1000].
	-231 <= Node.val <= 231 - 1
*/
class Solution {
private: 
    TreeNode* t1 = nullptr;
    TreeNode* t2 = nullptr;
    TreeNode* pre = nullptr;

    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        inOrder(root->left);
        if(pre != nullptr && pre->val > root->val){
            if (t1 == nullptr) t1 = pre;
            t2 = root;
        }
        pre = root;
        inOrder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        swap(t1->val, t2->val);
    }
};