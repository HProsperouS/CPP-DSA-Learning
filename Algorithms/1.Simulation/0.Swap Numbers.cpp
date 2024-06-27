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
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0]; 
        /*
            numbers[1] = (numbers[0] ^ numbers[1] ^ numbers[1])
            -> numbers[1] = (numbers[0] ^ 0) 

        */
        numbers[0] ^= numbers[1];
        return numbers;
    }
};