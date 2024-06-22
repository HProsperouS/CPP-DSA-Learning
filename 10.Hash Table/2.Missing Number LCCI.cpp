/*
Title:
面试题 17.04. Missing Number LCCI

Description:
An array contains all the integers from 0 to n, except for one number which is missing.  
Write code to find the missing integer. Can you do it in O(n) time?

Example 1:
	Input: [3,0,1]
	Output: 2

Example 2:
    Input: [9,6,4,2,3,5,7,0,1]
	Output: 8
	
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++){
            hash[ nums[i] ] = 1;
        }
        for(int i=0; ;i++){
            if(hash.find(i) == hash.end()) return i;
        }

        return -1;
    }
};