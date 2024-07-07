/*
Title:
1046. Last Stone Weight

Description:
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

Example 1:
	Input: stones = [2,7,4,1,8,1]
	Output: 1
	Explanation: 
	We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
	we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
	we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
	we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:
    Input: stones = [1]
	Output: 1
	
Constraints:
	1 <= stones.length <= 30
	1 <= stones[i] <= 1000
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
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            countingSort(stones);
            int n = stones.size();
            int v = stones[n-1] - stones[n-2];
            stones.pop_back(); // 移除最重的石头
            stones.pop_back(); // 移除次重的石头

            if (v || stones.size() ==0) {
                stones.push_back(v); // 结果不为0，添加新石头
            }
        }
        return stones[0];
    }
};