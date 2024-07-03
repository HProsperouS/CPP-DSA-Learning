/*
Title:
1984. Minimum Difference Between Highest and Lowest of K Scores

Description:
You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
Return the minimum possible difference.

Example 1:
	Input: nums = [90], k = 1
	Output: 0
	Explanation: There is one way to pick score(s) of one student:
	- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
	The minimum possible difference is 0.

Example 2:
    Input: nums = [9,4,1,7], k = 2
	Output: 2
	Explanation: There are six ways to pick score(s) of two students:
	- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
	- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
	- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
	- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
	- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
	- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
	The minimum possible difference is 2.
	
Constraints:
	1 <= k <= nums.length <= 1000
	0 <= nums[i] <= 105
*/
class Solution {
private:
    void insertionSort(std::vector<int>& arr) {
        int n = arr.size();
        for(int i=1; i<n; i++){
            int curr = arr[i];
            int j;

            for(j=i-1; j>=0; j--){
                if(curr < arr[j]){
                    arr[j+1] = arr[j];
                }else{
                    break;
                }
            }

            arr[j+1] = curr;
        }
    }
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size(); 
        insertionSort(nums);
        int ans = INT_MAX;

        for(int i=0; i + k - 1 < n; i++){
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};