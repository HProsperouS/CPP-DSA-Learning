/*
Title:
	LCP 17. Quick calculation robot
	
Description:
Xiao Kou found a speed calculating robot in the autumn market. The shopkeeper tells the robot two numbers (denoted as x and y), please say the calculation instructions:

"A" operation: make x = 2 * x + y;
"B" operation: y = 2 * y + x.
In this game, the number said by the shopkeeper is x = 1 and y = 0, and the calculation instruction said by the small button is recorded as A string s composed only of uppercase letters A and B. The order of the characters in the string indicates the calculation order, please return the sum of the final x and y.

Example 1:
	Input: s = "AB"
	Output: 4
	Explanation: 
	After an A operation, x = 2, y = 0. 
	Once again, after B operation, x = 2, y = 2. 
	The sum of x and y is going to be 4.

Tip:
	0 <= s.length <= 10
	s consists of 'A' and 'B'
	
*/
class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        int x=1,y=0;

        for(int i=0; i < len; i++){
            if(s[i] == 'A'){
                x = 2 * x + y;
            }else{
                y = 2 * y + x;
            }   
        }

        return x + y;
    }
};
