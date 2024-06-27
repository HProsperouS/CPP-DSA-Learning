/*
Title:
Question 16.01. Swap Numbers

Description:
Write a function that swaps the values of a and b in numbers = [a, b] without using temporary variables.

Example:
	Input: numbers = [1,2]
	Output: [2,1]

Constraints:
	numbers.length == 2
	-2147483647 <= numbers[i] <= 2147483647
	
*/
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        /*0 ^ 0 = 0
        1 ^ 1 = 0
        0 ^ 1 = 1
        1 ^ 0 = 1
        */
        numbers[0] ^= numbers[1];  // 1 ^ 2 = 3
        numbers[1] ^= numbers[0];  // 3 ^ 2 = 1
        /*
            numbers[1] = (numbers[0] ^ numbers[1] ^ numbers[1])
            -> numbers[1] = (1 ^ 0) 
            -> numbers[1] = 1
        */
        numbers[0] ^= numbers[1];
        /*
            numbers[0] = (numbers[0] ^ numbers[0] ^ numbers[1]);
            -> numbers[0] = ( 0 ^ 2)
            -> numbers[0] = 2
        */
        return numbers;
    }
};