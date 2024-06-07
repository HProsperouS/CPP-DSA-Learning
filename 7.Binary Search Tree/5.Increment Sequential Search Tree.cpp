/*
Title:
LCR 052. Increment Sequential Search Tree

Description:
Given a binary search tree, go through it in middle order and rearrange it into an ascending search tree, 
so that the leftmost node in the tree becomes the root node of the tree, 
and each node has no left child and only one right child.

Example 1:
	Input: root = [5,3,6,2,4, null, 8, 1, null, null, null, 7, 9]
	Output: [1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9]

Example 2:
    Input: root = [5,1,7]
	Output: [1,null,5,null,7]
	
Constraints:
	The number of nodes in the tree ranges from [1, 100]
	0 <= Node.val <= 1000
*/
class Solution {
private:
    vector<int> ret;
    void inOrder(TreeNode* node){
        if(node == NULL){
            return;
        }
        inOrder(node->left);
        ret.push_back(node->val);
        inOrder(node->right);
    }
    TreeNode* insert(TreeNode* node, int val){
        if(node == nullptr){
            return new TreeNode(val);
        }
        if(val < node->val){
            node->left = insert(node->left, val);
        }else{
            node->right = insert(node->right, val);
        }

        return node;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = nullptr;
        inOrder(root);

        for(int i=0; i < ret.size(); i++){
            newRoot = insert(newRoot, ret[i]);
        }

        return newRoot;
    }
	
	TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(-1);
        TreeNode* curr = head;
        inOrder(root);

        for(int i=0; i < ret.size(); i++){
            TreeNode* temp = new TreeNode(ret[i]);
            curr->right = temp;
            curr = curr->right;
        }

        return head->right;
    }
};