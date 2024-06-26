/*
Title:
540. Single Element in a Sorted Array

Description:
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
	Input: nums = [1,1,2,3,3,4,4,8,8]
	Output: 2

Example 2:
    Input: nums = [3,3,7,7,10,11,11]
	Output: 10
	
Constraints:
	1 <= nums.length <= 105
	0 <= nums[i] <= 105
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
        int low = 0; int high = nums.size()-1;

        while(low < high){
            int mid = (high - low) / 2 + low; //Avoid overflow compared to (high + low) / 2;
            if(nums[mid] == nums[mid ^ 1]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }

        return nums[low];
    }

};

/* 
Example 1: mid = 4
nums[mid] = nums[4] = 3;
mid ^ 1 = 4 ^ 1 = 5;  // 4的二进制是100，100 ^ 001 = 101，即5
nums[mid ^ 1] = nums[5] = 4;

Example 2: mid = 2
nums[mid] = nums[2] = 2;
mid ^ 1 = 2 ^ 1 = 3;  // 2的二进制是10，010 ^ 001 = 011，即3
nums[mid ^ 1] = nums[3] = 3;
*/