/*
Title:
108. Convert Sorted Array to Binary Search Tree

Description:
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Example 1:
	Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
    Input: nums = [1,3]
    Output: [3,1]
    Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
	
Constraints:
	1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in a strictly increasing order.
*/

class Solution {
private:
    TreeNode* SortedArrary(vector<int>& nums, int l, int r){
        if(l > r){
            return NULL;
        }

        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = SortedArrary(nums, l, mid - 1);
        node->right = SortedArrary(nums, mid + 1, r);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return SortedArrary(nums, 0 , nums.size()-1);
    }

    
};

