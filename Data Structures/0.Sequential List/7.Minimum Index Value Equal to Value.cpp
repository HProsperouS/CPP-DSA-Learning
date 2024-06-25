/*
Title:
Minimum Index Value Equal to Value

Description:
You are given an integer array nums where the index starts from 0. Return the minimum index i such that i mod 10 == nums[i]. If there is no such index, return -1.

Here, x mod y denotes the remainder of x divided by y.

Example 1:
    Input: nums = [0,1,2]
    Output: 0
    Explanation: 
    i=0: 0 mod 10 = 0 == nums[0].
    i=1: 1 mod 10 = 1 == nums[1].
    i=2: 2 mod 10 = 2 == nums[2].
    All indices satisfy i mod 10 == nums[i], so return the minimum index 0.

Example 2:
    Input: nums = [4,3,2,1]
    Output: 2
    Explanation:
    i=0: 0 mod 10 = 0 != nums[0].
    i=1: 1 mod 10 = 1 != nums[1].
    i=2: 2 mod 10 = 2 == nums[2].
    i=3: 3 mod 10 = 3 != nums[3].
    Index 2 is the only one that satisfies i mod 10 == nums[i].

Example 3:
    Input: nums = [1,2,3,4,5,6,7,8,9,0]
    Output: -1
    Explanation: There is no index that satisfies i mod 10 == nums[i].

Example 4:
    Input: nums = [2,1,3,5,2]
    Output: 1
    Explanation: Index 1 is the only one that satisfies i mod 10 == nums[i].

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 9
*/

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int index = -1;
        for(int i = 0; i < nums.size(); i++){
            if(i % 10 == nums[i]){
                index = i;
                break;
            }
        }
        return index;
    }
};
