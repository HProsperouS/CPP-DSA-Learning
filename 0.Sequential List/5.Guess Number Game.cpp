/*
Title:
Guess Number Game

Description:
Little A and Little B are playing a number guessing game. Each time, Little B randomly selects one number from 1, 2, 3, and Little A also guesses one number from 1, 2, 3. They play this game three times in total. Please return how many times Little A guessed correctly.

Input:
The guess array contains Little A's guesses each time, and the answer array contains Little B's selections each time. The lengths of guess and answer are both 3.

Example 1:
Input: guess = [1,2,3], answer = [1,2,3]
Output: 3
Explanation: Little A guessed correctly each time.

Example 2:
Input: guess = [2,2,3], answer = [3,2,1]
Output: 1
Explanation: Little A only guessed correctly the second time.

Constraints:
The length of guess is 3.
The length of answer is 3.
The elements of guess are one of {1, 2, 3}.
The elements of answer are one of {1, 2, 3}.
*/

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int count = 0;
        for(int i=0; i < 3; i++){
            if(guess[i] == answer[i]){
                count++;
            }
        }
        return count;
    }
};