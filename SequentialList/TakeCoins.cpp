/*
Title:
Take Coins

Description:
On the table are n piles of LeetCode coins, with the quantity of each pile stored in the array coins. At each turn, we can choose any pile and take either one or two coins from it. We need to find the minimum number of turns required to take all the LeetCode coins.

Example 1:
    Input: [4,2,1]
    Output: 4
    Explanation: We need to take 2 coins from the first pile, 1 coin from the second pile, and 1 coin from the third pile, for a total of 4 turns.

Example 2:
    Input: [2,3,10]
    Output: 8

Constraints:
    1 <= n <= 4
    1 <= coins[i] <= 10
*/

class Solution {
public:
    int minCount(vector<int> &coins) {
        int count = 0;
        for(int i=0; i<coins.size(); i++){
            int countPile = (coins[i] + 1) / 2;
            count += countPile;
        }
        return count;
    }
};