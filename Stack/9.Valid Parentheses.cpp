/*
Title:
Leetcode 20. Valid Parentheses

Description:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example 1:
	Input: s = "()"
	Output: true
	
Example 2:
	Input: s = "()[]{}"
	Output: true
	
Example 3:
	Input: s = "(]"
	Output: false
	
Constraints:
	1 <= s.length <= 104
	s consists of parentheses only '()[]{}'.
	
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char ch : s){
            if(isLeft(ch)){
                stk.push(ch);
            }else{
                if(stk.empty()){
                    return false;
                }else{
                    if(!isMatch(stk.top(),ch)){
                        return false;
                    }
                    //Remove the top if isMatched
                    stk.pop();
                }
            }
        }

        return true;
    }

    bool isLeft(char c){
        return c == '(' || c == '[' || c == '{';
    }
    bool isMatch(char left, char right){
        return left == '(' && right == ')' ||
        left == '[' && right == ']' ||
        left == '{' && right == '}';
    }
};