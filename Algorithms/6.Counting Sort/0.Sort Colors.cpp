/*
Title:
75. Sort Colors

Description:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
	Input: nums = [2,0,2,1,1,0]
	Output: [0,0,1,1,2,2]

Example 2:
    Input: nums = [2,0,1]
	Output: [0,1,2]
	
Constraints:
	n == nums.length
	1 <= n <= 300
	nums[i] is either 0, 1, or 2.
*/
class Solution {
private:
    void countingSort(vector<int>& arr){
        if(arr.empty()) return;

        int maxVal = *max_element(arr.begin(), arr.end());
        int minVal = *min_element(arr.begin(), arr.end());

        // [2,0,2,1,1,0]
        int range = maxVal - minVal + 1; // 2 - 0 + 1 = 3
        vector<int> count(range, 0); //[0,0,0]

        for (int num : arr) {
            count[num - minVal]++; //[2,2,2]
        }

        for (size_t i = 1; i < count.size(); i++) {
            count[i] += count[i - 1]; //[2,4,6]
        }

        vector<int> output(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[--count[arr[i] - minVal]] = arr[i];
        }

        arr = output;
    }

public:
    void sortColors(vector<int>& nums) {
        countingSort(nums);
    }
};