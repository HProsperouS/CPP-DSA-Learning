/*
Title:
450. Delete Node in a BST

Description:
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

Example 1:
	Input: root = [5,3,6,2,4,null,7], key = 3
	Output: [5,4,6,2,null,null,7]
	Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
	One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
	Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
    Input: root = [5,3,6,2,4,null,7], key = 0
	Output: [5,3,6,2,4,null,7]
	Explanation: The tree does not contain a node with value = 0.
	
Constraints:
	Input: root = [], key = 0
	Output: []
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* node, int key) {
        if(node == nullptr){
            return NULL;
        }

        if(key < node->val){
            node->left = deleteNode(node->left, key);
        }else if(key > node->val){
            node->right = deleteNode(node->right, key);
        }else{
            if(node->left == NULL && node->right==NULL){
                delete node;
                return NULL;
            }else if(node->left == NULL){
                //node->right is not null
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }else if(node->right == NULL){
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }else{
                //both left and right not null;
                TreeNode* temp = node->right;
                while(temp->left != NULL){
                    temp = temp->left; // Find the leftmost node in the right subtree
                }
                node->val = temp->val;
                node->right = deleteNode(node->right, temp->val); // Remove the leftmost node in the right subtree
            }
        }

        return node;
    }
};