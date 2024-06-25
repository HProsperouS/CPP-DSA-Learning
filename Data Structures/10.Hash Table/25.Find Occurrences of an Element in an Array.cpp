/*
Title:
3159. Find Occurrences of an Element in an Array

Description:
You are given an integer array nums, an integer array queries, and an integer x.
For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.
Return an integer array answer containing the answers to all queries.

Example 1:
	Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1
	Output: [0,-1,2,-1]
	Explanation:
	For the 1st query, the first occurrence of 1 is at index 0.
	For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
	For the 3rd query, the second occurrence of 1 is at index 2.
	For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.

Example 2:
    Input: nums = [1,2,3], queries = [10], x = 5
	Output: [-1]
	Explanation:
	For the 1st query, 5 doesn't exist in nums, so the answer is -1.
 
Constraints:
	1 <= nums.length, queries.length <= 105
	1 <= queries[i] <= 105
	1 <= nums[i], x <= 104
*/
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, vector<int>> positions; // 记录每个数出现的所有位置
        vector<int> answer;

        // 遍历 nums 记录 x 的位置
        for (int i = 0; i < nums.size(); ++i) {
            positions[nums[i]].push_back(i);
        }

        // 遍历 queries 检查每个查询
        for (int i = 0; i < queries.size(); ++i) {
            int k = queries[i];

            // 如果第 k 个 x 存在，返回其下标，否则返回 -1
            if (k <= positions[x].size()) {
                answer.push_back(positions[x][k - 1]);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};